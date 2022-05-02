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

  for (int i=0; i<N; i += 2) {
    n[i] = A[C[0][i % 3] - 65];
    n[i + 1] = A[C[1][i % 3] - 65];
  }

  for (int i=0; i<N; i++) printf("%d ", n[i]);

  return 0;
}

// CJM
// HER

// 1 2 2
// 3 3 2

// 1 3 2 3 2 2