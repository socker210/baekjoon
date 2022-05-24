#include <iostream>

using namespace std;

int main() {
  int N;

  scanf("%d", &N);

  int a = 1, b = 1, t = 0;

  for (int i=2; i<=N; i++) {
    t = b;
    b = a + b;
    a = t;

    if (b >= 15746) b -= 15746;
  }

  printf("%d", b);

  return 0;
}