#include <iostream>

using namespace std;

const int N_SIZE = 16;

int main() {
  char C[2][9];
  int N[N_SIZE];

  scanf("%s %s", C[0], C[1]);

  for (int i=0; i<N_SIZE; i++) N[i] = C[i % 2][i / 2] - 48;

  for (int i=0; i<N_SIZE - 2; i++)
    for (int j=0; j<N_SIZE - i - 1; j++) N[j] = (N[j] + N[j + 1]) % 10;

  printf("%d%d", N[0], N[1]);

  return 0;
}