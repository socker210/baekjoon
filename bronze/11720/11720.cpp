#include <iostream>

using namespace std;

int main() {
  int N, s = 0;

  scanf("%d", &N);

  char n[N + 1];

  cin >> n;

  for (int i=0; i<N; i++) s += n[i] - '0';

  printf("%d", s);

  return 0;
}