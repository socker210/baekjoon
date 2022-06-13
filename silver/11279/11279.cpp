#include <iostream>
using namespace std;

void swap(int* a, int* b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("example.txt", "r", stdin);
  int N;
  cin >> N;
  int heap[N],s=0;
  while(N--) {
    int n, i;
    cin >> n;
    if (n == 0) {
      if (s == 0) cout << 0 << '\n';
      else {
        cout << heap[0] << '\n';
        i = 0;
        heap[i] = heap[--s];
        while(true) {
          if (i * 2 >= s) break;
          if (i * 2 + 2 > s) {
            swap(&heap[i], &heap[i * 2 + 1]);
            break;
          }
          int* ptr = &heap[i * 2 + 1];
          int c_idx = *ptr > *(ptr+1) ? i * 2 + 1 : i * 2 + 2;
          if (heap[c_idx] > heap[i]) swap(&heap[i], &heap[c_idx]);
          else break;
          i = c_idx;
        }
      }
    } else {
      i = s;
      heap[s++] = n;
      while(i != 0 && heap[i] > heap[(i - 1) / 2]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
      }
    }
  }
}