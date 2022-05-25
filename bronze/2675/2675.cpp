#include <iostream>

using namespace std;

int main() {
  int N, c;
  char t[20];

  scanf("%d", &N);

  for (;N;N--) {
    scanf("%d %s", &c, t);

    int len = 0, i = 0;

    while (t[i++] != '\0') len += 1;

    for (i=0; i<c * len; i++) printf("%c", t[i / c]);

    printf("\n");
  }

  return 0;
}