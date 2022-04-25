#include <iostream>
#include <string>

using namespace std;

int pow(int base, int exp) {
  int res = 1;

  while(exp--) {
    res *= base;
  }

  return res;
}

int main() {
  string V[3];
  string colors[10] = {"black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white"};
  long R[3];

  cin >> V[0] >> V[1] >> V[2];

  for (int i=0; i<3; i++) {
    for (int j=0; j<10; j++) {
      if (V[i] == colors[j]) {
        R[i] = i == 2 ? pow(10, j) : j;
      }
    }
  }

  cout << (R[0] * R[2] * 10)+(R[1] * R[2]);

  return 0;
}