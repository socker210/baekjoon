#include <iostream>

using namespace std;

void swap(int* n1, int* n2) {
  int t = *n1;

  *n1 = *n2;
  *n2 = t;
}

void sort(int n[], int start, int end) {
  if (start >= end) return;

  int pivot = start;
  int left = start + 1;
  int right = end;

  while(left <= right) {
    while(left <= end && n[left] < n[pivot]) left++;
    while(right >= start && n[right] > n[pivot]) right--;
    
    if (left > right) swap(&n[right], &n[pivot]);
    else swap(&n[left], &n[right]);
  }

  sort(n, start, right - 1);
  sort(n, right + 1, end);
}

int main() {
  int N;

  scanf("%d", &N);

  int n[N];

  for (int i=0; i<N; i++) scanf("%d", &n[i]);

  sort(n, 0, N - 1);

  for (int i=0; i<N; i++) cout << n[i] << endl;

  return 0;
}