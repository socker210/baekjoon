/** 배열로 처리, shift처리 하는게 아니라 front, rear로 처리하면 될듯, 시간 복잡도는 O(1)로 처리하자 */
#include <iostream>
#include <cstring>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("example.txt", "r", stdin);
  int N;
  char cmd[11];
  cin >> N;
  int deque[N], front, rear;
  front = rear = 0;
  for (int i=0; i<N; i++) {
    cin >> cmd;
    if (strcmp(cmd, "push_front") == 0);
    if (strcmp(cmd, "push_back") == 0);
    if (strcmp(cmd, "pop_front") == 0);
    if (strcmp(cmd, "pop_back") == 0);
    if (strcmp(cmd, "size") == 0);
    if (strcmp(cmd, "empty") == 0);
    if (strcmp(cmd, "front") == 0);
    if (strcmp(cmd, "back") == 0);
  }
}