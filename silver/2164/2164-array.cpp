#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  freopen("example.txt", "r", stdin);

  int N; cin >> N;

  int Q[N], front, rear;

  front = 0;
  rear = N - 1;

  for (int i=0; i<N; i++) Q[i] = i + 1;

  for (int i=1; i<N; i++) {
    front++;

    int t = Q[front];

    for (int j=front; j<rear; j++) Q[j] = Q[j+1];

    Q[rear] = t;
  }

  cout << Q[front];

  return 0;
}
