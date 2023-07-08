import fs from 'fs'
import path from 'path'
import { exec, spawn } from 'child_process'
import { fileURLToPath } from 'url'
import commandLineArgs from 'command-line-args'

function replaceExt(filename, ext = '.cpp', replaceStr = '', withExt = false) {
  return filename.replace(ext, replaceStr) + (withExt ? ext : '')
}

async function findFilePath(dirname, targetFileName, excludeDirs) {
  function find(dirname) {
    const filenames = fs
      .readdirSync(dirname)
      .filter((content) => !excludeDirs.includes(content))

    for (const filename of filenames) {
      const nextDirname = path.join(dirname, filename)
      const stat = fs.statSync(nextDirname)

      if (stat.isDirectory()) {
        const res = find(nextDirname)

        if (res) {
          return res
        }
      }

      if (filename === targetFileName) {
        return { dirname, filename }
      }
    }
  }

  return find(dirname)
}

function getInputData(pathname) {
  try {
    return fs.readFileSync(pathname).toString().split('\n\n')
  } catch (e) {
    return []
  }
}

function spawnChild(pathname, inputData) {
  const child = spawn(pathname)

  if (inputData) {
    child.stdin.write(inputData)
    child.stdin.end()
  }

  child.stdout.on('data', printOutData)
  child.stderr.on('data', printErrData)

  return child
}

function printOutData(data) {
  console.log(data.toString())
}

function printErrData(data) {
  console.log(data.toString())
}

function compileCpp(dirname, filename) {
  return new Promise((resolve, reject) => {
    exec(`g++ ${dirname} -o ${filename} -std=c++17`, (err) => {
      if (err) {
        return reject(err)
      }

      resolve()
    })
  })
}

async function main() {
  const __dirname = path.dirname(fileURLToPath(import.meta.url))

  const args = commandLineArgs([
    {
      name: 'file',
      alias: 'f',
      type: String,
      defaultOption: true,
    },
    {
      name: 'input',
      alias: 'i',
      type: String,
      defaultValue: 'input',
    },
  ])

  if (!args.file) {
    throw new Error('어떠한 파일을 실행하시겠습니까?')
  }

  const targetFileName = replaceExt(args.file, '.cpp', '', true)

  const fileRes = await findFilePath(__dirname, targetFileName, [
    'node_modules',
    '.git',
  ])

  if (!fileRes) {
    throw new Error('해당 파일을 찾을 수 없습니다')
  }

  const filePathname = path.join(fileRes.dirname, fileRes.filename)
  const inputPathname = path.join(fileRes.dirname, args.input)
  const outPathname = path.join(fileRes.dirname, replaceExt(fileRes.filename))

  await compileCpp(filePathname, outPathname)

  const inputData = getInputData(inputPathname)

  if (!inputData.length) {
    return spawnChild(outPathname)
  }

  for (const data of inputData) {
    spawnChild(outPathname, data)
  }
}

main()
