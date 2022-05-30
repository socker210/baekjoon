#include <iostream>

using namespace std;

int main() {
  int v, l, i;

  scanf("%d %d", &v, &l);

  for (i=0; i<v-l; i++) printf("%d %d\n", i, i + 1);
  for (i=v-l+1; i<v; i++) printf("%d %d\n", v-l, i);

  return 0;
}
