import fs from 'fs'
import path from 'path'
import { fileURLToPath } from 'url'
import inquirer from 'inquirer'
import chalk from 'chalk'

const __dirname = path.dirname(fileURLToPath(import.meta.url))

function createREADME(pathname, problem) {
  const template = `## 문제 링크\n\n- https://www.acmicpc.net/problem/${problem}`

  fs.writeFileSync(path.join(pathname, 'README.md'), template, {
    encoding: 'utf-8',
  })
}

function createInput(pathname) {
  fs.writeFileSync(path.join(pathname, 'input'), '', { encoding: 'ascii' })
}

function createCpp(pathname, problem) {
  const template = `#include <iostream>\n\nusing namespace std;\n\nint main() {\n\treturn 0;\n}`

  fs.writeFileSync(path.join(pathname, `${problem}.cpp`), template, {
    encoding: 'ascii',
  })
}

function createDir(pathname) {
  fs.mkdirSync(pathname)
}

function isExistDir(dirname) {
  return fs.existsSync(dirname)
}

function isExistProblem(dirname, level, problem) {
  if (!isExistDir(path.join(dirname, level))) {
    return false
  }

  const excludeDirs = ['node_modules', '.git']

  const find = (dirname) => {
    const dirContents = fs
      .readdirSync(dirname)
      .filter((value) => !excludeDirs.includes(value))

    for (const content of dirContents) {
      const nextPathname = path.join(dirname, content)

      if (content === problem) {
        return true
      }

      if (fs.statSync(nextPathname).isDirectory()) {
        if (find(nextPathname)) {
          return true
        }
      }
    }
  }

  return find(path.join(dirname, level)) ?? false
}

function isNumber(value) {
  return /^[0-9]+$/.test(value)
}

inquirer
  .prompt([
    {
      type: 'list',
      name: 'level',
      message: '어느 단계의 문제를 푸시겠습니까?',
      choices: [
        {
          name: 'Ruby',
          value: 'ruby',
        },
        {
          name: 'Diamond',
          value: 'diamond',
        },
        {
          name: 'Platinum',
          value: 'platinum',
        },
        {
          name: 'Gold',
          value: 'gold',
        },
        {
          name: 'Silver',
          value: 'silver',
        },
        {
          name: 'Bronze',
          value: 'bronze',
        },
      ],
    },
    {
      type: 'input',
      name: 'problem',
      message: '어떤 문제를 푸시겠습니까?',
      validate: (problem, { level }) => {
        if (!isNumber(problem)) {
          return '문제는 숫자만 입력 가능합니다'
        }

        if (isExistProblem(__dirname, level, problem)) {
          return '해당 문제가 이미 존재합니다'
        }

        return true
      },
    },
    {
      type: 'confirm',
      name: 'isInput',
      message: '예제 입력을 사용하시겠습니까?',
      default: true,
    },
  ])
  .then(({ level, problem, isInput }) => {
    const levelPathname = path.join(__dirname, level)
    const problemPathname = path.join(levelPathname, problem)

    if (!isExistDir(levelPathname)) {
      createDir(levelPathname)
    }

    createDir(problemPathname)

    createCpp(problemPathname, problem)

    createREADME(problemPathname, problem)

    if (isInput) {
      createInput(problemPathname)
    }

    console.log(chalk.blue('생성되었습니다'))
  })
