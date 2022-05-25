#include <iostream>

using namespace std;

int main() {
  char N[101];
  int n[26];

  scanf("%s", N);

  for (int i=0; i<26; i++) n[i] = -1;

  int i = 0;

  while(N[i] != '\0') {
    int idx = N[i] - 'a';

    n[idx] = n[idx] == -1 ? i : n[idx];

    i++;
  }

  for (int i=0; i<26; i++) printf("%d ", n[i]);

  return 0;
}