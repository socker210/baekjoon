#include <iostream>

using namespace std;

int main() {
  char N[16];
  int dial[26];
  int i;

  scanf("%s", N);

  for(i='A'; i<='Z'; i++) {
    int dial_n;

    if (i == 'Z') dial_n = (i - 'A' - 2) / 3 + 3;
    else if (i == 'S' || i >= 'V') dial_n = (i - 'A' - 1) / 3 + 3;
    else dial_n = (i - 'A') / 3 + 3;

    dial[i - 'A'] = dial_n;
  }

  int sum = 0;

  i = 0;

  while(N[i] != '\0') sum += dial[N[i++] - 'A'];

  printf("%d", sum);

  return 0;
}