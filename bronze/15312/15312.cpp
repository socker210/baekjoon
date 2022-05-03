#include <iostream>

using namespace std;

int A[26] = {3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};
char C[2][2001];

int main() {
  scanf("%s %s", C[0], C[1]);

  int N = 0;

  while(C[0][N] != '\0') N++;

  N *= 2;

  int n[N];
  int cnt = 0;

  for (int i=0; i<N; i++) n[i] = A[C[i % 2][i / 2] - 65];

  while(cnt != N - 2) {
    for (int i=0; i<N - 1 - cnt; i++) n[i] = (n[i] + n[i + 1]) % 10;

    cnt++;
  }

  printf("%d%d", n[0], n[1]);

  return 0;
}