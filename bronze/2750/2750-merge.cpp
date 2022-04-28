#include <iostream>

using namespace std;

void merge(int n[], int s, int m, int e) {
  int T = e - s + 1;
  int t[T];
  int i = s;
  int j = m + 1;
  int t_idx = 0;

  while(i <= m && j <= e) {
    if (n[i] < n[j]) {
      t[t_idx] = n[i];

      i++;
    } else {
      t[t_idx] = n[j];

      j++;
    }

    t_idx++;
  }

  if (i <= m)
    for (int k=i; k<=m; k++) t[t_idx++] = n[k];

  if (j <= e)
    for (int k=j; k<=e; k++) t[t_idx++] = n[k];

  for (int k=0; k<T; k++) n[s + k] = t[k];
}

void mergeSort(int n[], int s, int e) {
  if (s < e) {
    int m = (s + e) / 2;

    mergeSort(n, s, m);
    mergeSort(n, m + 1, e);
    merge(n, s, m, e);
  }
}

int main() {
  int N;
    
  scanf("%d", &N);
    
  int n[N];
  
  for (int i=0; i<N; i++) scanf("%d", &n[i]);
    
  mergeSort(n, 0, N - 1);

  for (int i=0; i<N; i++) printf("%d ", n[i]);

  return 0;
}