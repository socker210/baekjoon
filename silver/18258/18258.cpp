#include <iostream>
#include <cstring>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  freopen("example.txt", "r", stdin);

  int N; cin >> N;
  
  int Q[N], front, rear;
  char cmd[6];

  front = rear = -1;

  for (int i=0; i<N; i++) {
    cin >> cmd;

    if (strcmp(cmd, "push") == 0) {
      if (rear != N - 1) {
        int t; cin >> t;

        front = front == -1 ? 0 : front;
        rear++;

        Q[rear] = t;
      }
    }

    if (strcmp(cmd, "pop") == 0) {
      if (front == -1 || front > rear) cout << -1 << '\n';
      else cout << Q[front++] << '\n';
    }

    if (strcmp(cmd, "size") == 0) {
      if (front == -1 || front > rear) cout << 0 << '\n';
      else cout << rear - front + 1 << '\n';
    }

    if (strcmp(cmd, "empty") == 0) {
      cout << (front == -1 || front > rear ? 1 : 0) << '\n';
    }

    if (strcmp(cmd, "front") == 0) {
      cout << (front == -1 || front > rear ? -1 : Q[front]) << '\n';
    }

    if (strcmp(cmd, "back") == 0) {
      cout << (front == -1 || front > rear ? -1 : Q[rear]) << '\n';
    }
  }
  
  return 0;
}