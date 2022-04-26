#include <iostream>

using namespace std;

void swap(int* n1, int* n2) {
  int t = *n1;

  *n1 = *n2;
  *n2 = t;
}

int main() {
  int N;

  scanf("%d", &N);

  int n[N];

  for(int i=0; i<N; i++) scanf("%d", &n[i]);

  // Selection sort
  for (int i=0; i<N - 1; i++) {
    int m = i;

    for (int j=i + 1; j<N; j++)
      if (n[j] < n[m]) m = j;

    swap(&n[i], &n[m]);
  }

  for (int i=0; i<N; i++) cout << n[i] << endl;

  return 0;
}
