#include <iostream>

using namespace std;

int main() {
  char N[2][4];
  int n[2];

  cin >> N[0] >> N[1];

  for (int i=0; i<2; i++) n[i] = (N[i][2] - '0') * 100 + (N[i][1] - '0') * 10 + (N[i][0] - '0');

  printf("%d", n[0] > n[1] ? n[0] : n[1]);

  return 0;
}