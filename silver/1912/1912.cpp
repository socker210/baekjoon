#include <iostream>

using namespace std;

#define Max(a,b) (a>b?a:b)

int main() {
  int N, n;

  scanf("%d", &N);

  int DP[N];
  int s[N];
  int t[N];

  for (int i=0; i<N; i++) {
    scanf("%d", &n);

    if (i == 0) {
      t[i] = n;
      s[i] = n;
      DP[i] = n;
    } else {
      t[i] = n;
      s[i] = s[i - 1] < 0 ? t[i] : s[i - 1] + t[i];
      DP[i] = Max(Max(s[i], DP[i - 1]), Max(t[i], t[i - 1] + t[i]));
    }
  }

  printf("%d", DP[N - 1]);

  return 0;
}
