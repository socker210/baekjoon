#include <iostream>

using namespace std;

void swap(int* n1, int* n2) {
  int t = *n1;

  *n1 = *n2;
  *n2 = t;
}

int main() {
  int a, b, c;

  scanf("%d %d %d", &a, &b, &c);

  if (b < a) swap(&a, &b);
  if (c < a) swap(&a, &c);
  if (b > c) swap(&b, &c);

  printf("%d %d %d", a, b, c);

  return 0;
}