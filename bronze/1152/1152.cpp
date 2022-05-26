#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
  string str, buf;

  getline(cin, str);

  istringstream ss(str);

  int idx = 0;

  while(getline(ss, buf, ' ')) {
    if(buf.length() != 0) idx++;
  }

  printf("%d", idx);

  return 0;
}