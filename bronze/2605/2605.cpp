#include <iostream>

using namespace std;

int main() {
  int N;

  scanf("%d", &N);

  int n[N];
  int arr[N];

  for (int i=0; i<N; i++) {
    scanf("%d", &n[i]);

    arr[i] = i + 1;
  }

  for (int i=0; i<N; i++) {
    int t = arr[i];

    for (int j=i; j>i - n[i]; j--) arr[j] = arr[j - 1];

    arr[i - n[i]] = t;
  }

  for (int i=0; i<N; i++) printf("%d ", arr[i]);

  return 0;
}