#include <iostream>
using namespace std;

void swap(int* a, int* b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  freopen("example.txt", "r", stdin);
  int N;
  cin >> N;
  while(N--) {
    int C, T;
    cin >> C >> T;
    int queue[C], heap[C], s = 0;
    for (int i=0; i<C; i++) {
      int n, j;
      cin >> n;
      j = s;
      heap[s] = n;
      queue[i] = n;
      while(j != 0 && heap[j] > heap[(j - 1) / 2]) {
        swap(&heap[j], &heap[(j - 1) / 2]);
        j = (j - 1) / 2;
      }
      s++;
    }
    int target_idx = T;
    while(true) {
      int front, rear, cnt;
      front = cnt = 0;
      rear = C - 1;
      if (heap[0] == queue[front]) {
        if (target_idx == 0) {
          cout << cnt << '\n';
          break;
        } else {
          int j;
          s--;
          j = 0;
          swap(&heap[j], &heap[s]);
          while(true) {
            if (j >= s - 1) break;
            int c_idx = j + 2 > s - 1 ? j + 1 : heap[j + 1] > heap[j + 2] ? j + 1 : j + 2;
            if (heap[c_idx] > heap[j]) swap(&heap[c_idx], &heap[j]);
            else break;
            j = c_idx;
          }
          front++;
        }
        target_idx--;
      } else {
        // TODO: 이거 오류 찾기
        int t = queue[front];
        for (int i=front+1; i<rear-1; i++) queue[i-1] = queue[i];
        queue[rear] = t;
        cnt++;
        target_idx = t == queue[target_idx] ? rear : target_idx - 1;
      }
    }
  }
}