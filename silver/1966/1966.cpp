#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  freopen("example.txt", "r", stdin);
  int N; cin >> N;
  while(N--) {
    int C, T;
    cin >> C >> T;
    int arr[C];
    for (int i=0; i<C; i++) {
      int t;
      cin >> t;
      arr[i] = t;
    }
    for (int i=(C/2)-1; i>=0; i--) {
      cout << i << ' ' <<  i * 2 + 1 << ' ' << i * 2 + 2 << '\n';
    }


    // for (int i=0; i<C; i++) cout << arr[i] << '\n';
  }
  return 0;
}

// 0 -> 1, 2
// 1 -> 3, 4
// 2 -> 5

// i=0; i<6; i++

// 루트 -> (i - 1) / 2
// 왼쪽 -> i * 2 + 1
// 오른쪽 -> i * 2 + 2

// 0: 루트
// 1: 루트 왼쪽 
// 2: 루트 오른쪽
// 3: 루트 왼쪽 왼쪽
// 4: 루트 왼쪽 오른쪽
// 5: 루트 오른쪽 왼쪽