#include <iostream>

using namespace std;

typedef struct Node {
  int priority;
} Node;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  freopen("example.txt", "r", stdin);

  int N; cin >> N;

  while(N--) {
    int C, T;
    
    cin >> C >> T;

    Node* node_arr[C];

    for (int i=0; i<C; i++) {
      int t; cin >> t;

      Node* node = new Node;

      node->priority = t;

      node_arr[i] = node;
    }

    
    // TODO: 이거 우선순위 큐로 만들기
    // build heapify
    
  }

  return 0;
}