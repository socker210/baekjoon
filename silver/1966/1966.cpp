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
    int C, T, ans;
    cin >> C >> T;
    int heap[C], s = 0;
    for (int i=0;i <C;i ++) {
      int n, j;
      cin >> n;
      j = s;
      heap[s] = n;
      while(j != 0 && heap[j] > heap[(j - 1) / 2]) {
        swap(&heap[j], &heap[(j - 1) / 2]);
        j = (j - 1) / 2;
      }
      s++;
    }
    int t_val = heap[T], idx = 0;
    while(s--) {
      int j;
      j = 0;
      ans = heap[s] == t_val ? idx++ : ans;
      swap(&heap[j], &heap[s]);
      while(true) {
        // TODO: 이거 break조건 처리하기, 위의 ans처리하기
        int c_idx = heap[j + 1] > heap[j + 2] ? j + 1 : j + 2;
        if (heap[c_idx] > heap[j]) {
          swap(&heap[c_idx], &heap[j]);
          j = c_idx;
        }else break;
      }
    }
    cout << ans << '\n';
  }
}