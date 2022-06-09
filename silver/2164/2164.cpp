#include <iostream>

using namespace std;

typedef struct Node {
  int data;
  Node* next;
} Node;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  freopen("example.txt", "r", stdin);

  int N; cin >> N;

  Node* head = new Node;
  Node* tail;
  Node* p = head;

  for (int i=1; i<=N; i++) {
    p->data = i;

    if (i != N) {
      Node* next = new Node;  

      p->next = next;
      p = next;
    } else tail = p;
  }

  while(head->next != NULL && head->next->next != NULL) {
    p = head->next;

    delete head;
    
    head = p->next;

    p->next = NULL;
    tail->next = p;
    tail = p;
  }

  cout << tail->data;

  return 0;
}