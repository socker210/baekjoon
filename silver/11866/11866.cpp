#include <iostream>

using namespace std;

typedef struct Node {
  int data;
  Node* next;
} Node;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  freopen("example.txt", "r", stdin);

  int N, K; cin >> N >> K;
  int T[N];

  Node* front = new Node;
  Node* rear = NULL;

  Node* ptr = front;

  for (int i=1; i<=N; i++) {
    ptr->data = i;

    if (i != N) {
      Node* next = new Node;
      
      ptr->next = next;
      ptr = next;
    } else {
      rear = ptr;

      rear->next = NULL;
    }
  }

  int i = 1, t_idx = 0;

  while(front != NULL) {
    if (i % K == 0) {
      ptr = front;

      T[t_idx++] = front->data;
      front = front->next;

      delete ptr;
    } else {
      rear->next = front;
      rear = front;

      front = front->next;
      
      rear->next = NULL;
    }

    i++;
  }

  cout << '<';

  for (int i=0; i<N; i++) {
     cout << T[i];

     if (i != N -1) cout << ", ";
  }

  cout << '>';

  return 0;
}