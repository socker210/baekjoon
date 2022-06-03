#include <iostream>
#include <cstring>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  freopen("examples.txt", "r", stdin);

  int N;

  cin >> N;

  int n[N], top = -1;

  while(N--) {
    char cmd[6];
    int x;

    cin >> cmd;

    if (strcmp(cmd, "push") == 0) {
      cin >> x;

      n[++top] = x;
    }
    if (strcmp(cmd, "pop") == 0) cout << (top == -1 ? -1 : n[top--]) << '\n';
    if (strcmp(cmd, "size") == 0) cout << top + 1 << '\n';
    if (strcmp(cmd, "empty") == 0) cout << (top == -1 ? 1 : 0) << '\n';
    if (strcmp(cmd, "top") == 0) cout << (top == -1 ? -1 : n[top]) << '\n';
  }
}