#include <iostream>

using namespace std;

const int X = 0;
const int Y = 1;

void swap(int* n1[], int* n2[]) {
  int tx = *n1[X];
  int ty = *n1[Y];

  *n1[X] = *n2[X];
  *n1[Y] = *n2[Y];
  *n2[X] = tx;
  *n2[Y] = ty;
}

void quickSort(int n[][2], int start, int end) {
  if (start >= end) return;

  int pivot = start;
  int left = start + 1;
  int right = end;

  while(left <= right) {
    while(left <= end && (n[left][Y] == n[pivot][Y] ? n[left][X] <= n[pivot][X] : n[left][Y] <= n[pivot][Y])) left++;
    while(right >= start && (n[right][Y] == n[pivot][Y] ? n[right][X] > n[pivot][X] : n[right][Y] > n[pivot][Y])) right--;

    if (left > right) swap(n[right], n[pivot]);
    else swap(n[left], n[right]);
  }

  quickSort(n, start, right - 1);
  quickSort(n, right + 1, end);
}

int main() {
  int N;

  cin >> N;

  int n[N][2];

  for (int i=0; i<N; i++) scanf("%d %d", &n[i][X], &n[i][Y]);

  quickSort(n, 0, N - 1);

  for (int i=0; i<N; i++) cout << n[i][X] << " " << n[i][Y] << "\n";

  return 0;
}