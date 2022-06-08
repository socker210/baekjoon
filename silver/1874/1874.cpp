#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  freopen("example.txt", "r", stdin);

  int N;

  cin >> N;

  int S[N], T[N], o_idx = 0, t, top = -1, p = 0;
  char O[N * 2];

  for (int i=0; i<N; i++) {
    cin >> t;

    S[i] = t;
    T[++top] = i + 1;

    O[o_idx++] = '+';

    for (int j=p; top > -1 && S[j] == T[top]; j++) {
      O[o_idx++] = '-';

      top--;
      p++;
    }
  }

  if (top == -1) {
    for (int i=0; i<N * 2; i++) cout << O[i] << '\n';
  } else cout << "NO";
  

  return 0;
}