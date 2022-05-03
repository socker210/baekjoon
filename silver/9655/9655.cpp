#include <iostream>

using namespace std;

int main() {
  int N;

  scanf("%d", &N);

  int q = N / 3;
  int r = N % 3;

  if ((q + r) % 2 == 0) printf("CY");
  else printf("SK");

  return 0;
}
