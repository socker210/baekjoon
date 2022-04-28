#include <iostream>

using namespace std;

struct Coord {
  int x;
  int y;
};

void merge(Coord coords[], int s, int m, int e) {
  int T = e - s + 1; // 임시 배열 길이
  Coord t[T]; // 임시 배열
  int i = s; // 가운데 기준 좌측 비교 인덱스
  int j = m + 1; // 가운데 기준 우측 비교 인덱스
  int idx = 0; // 임시 배열 인덱스

  // 각 비교 인덱스가 증가될 수 있는 조건을 걸어 비교하여 임시 배열에 정렬된 데이터를 저장함.
  while(i <= m && j <= e) {
    // 문제의 조건이 y값이 서로 같을 경우 x로 정렬을 해야하니 아래와 같이 조건을 처리함.
    int coord_i = coords[i].y == coords[j].y ? coords[i].x : coords[i].y;
    int coord_j = coords[i].y == coords[j].y ? coords[j].x : coords[j].y;

    if (coord_i < coord_j) {
      t[idx] = coords[i];
      
      i++;
    } else {
      t[idx] = coords[j];

      j++;
    }

    idx++;
  }

  /**
   * i와 j를 비교하여 처리하기 때문에 한쪽만 작은값을 가져 데이터가 남아있을 수 있음.
   * 그러므로 이것을 체크하여 데이터를 그대로 넣어줌.
   *  작은 범위로 분할되어 작은것부터 해결하기 때문에 이미 정렬되어 있다는 가정이 가능함. (분할정복)
   */
  if (i <= m)
    for (int k=i; k<=m; k++) t[idx++] = coords[k];

  if (j <= e)
    for (int k=j; k<=e; k++) t[idx++] = coords[k];

  /**
   * 임시 배열에 정렬된 데이터를 실제 배열에 넣어줌.
   *  k 인덱스는 임시 배열을 기준으로 처리하고 실제 배열의 인덱스는 시작 인덱스를 더해줌.
   */
  for (int k=0; k<T; k++) coords[s + k] = t[k];
}

void mergeSort(Coord coords[], int s, int e) {
  /**
   * 시작점이 끝점보다 작을 경우에만 처리.
   * 시작점과 끝점이 같은 경우, 즉 하나로 분할된 경우에는 무시함.
   */
  if (s < e) {
    int m = (s + e) / 2;

    mergeSort(coords, s, m); // 가운데 기준 좌측 분할
    mergeSort(coords, m + 1, e); // 가운데 기준 우측 분할
    merge(coords, s, m, e); // 병합
  }
}

int main() {
  int N;
  
  scanf("%d", &N);

  Coord coords[N];

  for (int i=0; i<N; i++) scanf("%d %d", &coords[i].x, &coords[i].y);
  
  mergeSort(coords, 0, N - 1);

  for (int i=0; i<N; i++) printf("%d %d\n", coords[i].x, coords[i].y);
  
  return 0;
}