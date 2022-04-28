#include <iostream>

using namespace std;

void merge(int n[], int s, int m, int e) {
  int T = e - s + 1; // 임시 배열 크기 계산
  int t[T];
  int i = s; // s ~ m까지
  int j = m + 1; // m + 1 ~ e까지
  int t_idx = 0;

// i또는 j가 인덱스를 벗어날 경우 실행 안됨
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

  // 어느 한쪽만 다 pop되어 남아있는것이 존재할 경우 처리
  if (i <= m)
    for (int k=i; k<=m; k++) t[t_idx++] = n[k];

  if (j <= e)
    for (int k=j; k<=e; k++) t[t_idx++] = n[k];

  // 임시 배열 기준으로 반복문 실행. 원래 배열은 시작점부터 채워야하니 시작점을 더해줌
  for (int k=0; k<T; k++) n[s + k] = t[k];
}

void mergeSort(int n[], int s, int e) {
  if (s < e) {
    // middle 계산
    int m = (s + e) / 2;

    // 분할 먼저 처리
    // 왼쪽을 기준으로 가장 작은것부터 merge가 실행됨 (그렇게 재귀적으로 호출하고 있음)
    // 좌측이 다 정렬되면 우측이 정렬됨.
    // 그리고 마지막으로 병합 처리
    // 재귀적으로 계속 호출하니 콜스택 가장 윗 부분이 가장 작게 분할된 것임.
    mergeSort(n, s, m);
    mergeSort(n, m + 1, e);
    merge(n, s, m, e);
  }
}

int main() {
  // int n[4] = {4, 2, 3, 6};
  int n[8] = {4, 2, 3, 6, 7, 1, 0, 8};
  // int n[7] = {4, 2, 3, 6, 7, 1, 0};

  mergeSort(n, 0, 7);

  for (int i=0; i<8; i++) printf("%d ", n[i]);

  return 0;
}