#include <iostream>

using namespace std;

const int N = 9;

void swap(int* n1, int* n2) {
  int t = *n1;
  
  *n1 = *n2;
  *n2 = t;
}

void sort(int arr[]) {
  for (int i=0; i<N - 1; i++) {
    int m = i;
    for (int j=i + 1; j<N; j++) {
      if (arr[j] < arr[m]) m = j;
    }

    swap(&arr[i], &arr[m]);
  }
}

int sum(int arr[]) {
  int s = 0;

  for (int i=0; i<N; i++) s += arr[i];

  return s;
}

int main() {
  int n[N];
  int remain;
  int idx[2];

  for (int i=0; i<N; i++) scanf("%d", &n[i]);

  sort(n);

  remain = sum(n) - 100;

  for (int i=0; i<N - 1; i++) {
    for (int j=i + 1; j<N; j++) {
      if (n[i] + n[j] == remain) {
        idx[0] = i;
        idx[1] = j;
      }
    }
  }

  for (int i=0; i<N; i++) {
    if (i == idx[0] || i == idx[1]) continue;

    cout << n[i] << endl;
  }

  return 0;
}
