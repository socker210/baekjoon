#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("example.txt", "r", stdin);
  int N;
  char cmd[11];
  cin >> N;
  int deque[N], front, rear, size;
  front = rear = -1;
  size = 0;
  for (int i=0; i<N; i++) {
    cin >> cmd;
    if (strcmp(cmd, "push_front") == 0) {
      int t;
      cin >> t;
      if (front == -1) front = rear = 0;
      else front = front + 1 >= N ? 0 : front + 1;
      deque[front] = t;
      size++;
    }
    if (strcmp(cmd, "push_back") == 0) {
      int t;
      cin >> t;
      if (rear == -1) rear = front = 0;
      else rear = rear == 0 ? N - 1 : rear - 1;
      deque[rear] = t;
      size++;
    }
    if (strcmp(cmd, "pop_front") == 0) {
      if (front == -1) cout << -1 << '\n';
      else {
        cout << deque[front] << '\n';
        if (front == rear) front = rear = -1;
        else front = front - 1 < 0 ? N - 1 : front - 1;
        size--;
      }
    }
    if (strcmp(cmd, "pop_back") == 0) {
      if (rear == -1) cout << -1 << '\n';
      else {
        cout << deque[rear] << '\n';
        if (front == rear) front = rear = -1;
        else rear = rear + 1 >= N ? 0 : rear + 1;
        size--;
      }
    }
    if (strcmp(cmd, "size") == 0) cout << (front == -1 && rear == -1 ? 0 : size) << '\n';
    if (strcmp(cmd, "empty") == 0) cout << (front == -1 && rear == -1? 1 : 0) << '\n';
    if (strcmp(cmd, "front") == 0) cout << (front == -1 ? -1 : deque[front]) << '\n';
    if (strcmp(cmd, "back") == 0) cout << (rear == -1 ? -1 : deque[rear]) << '\n';
  }
  return 0;
}