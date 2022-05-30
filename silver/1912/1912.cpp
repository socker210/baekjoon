#include <iostream>

using namespace std;

#define Max(a,b) (a>b?a:b)

int main() {
  int N, n;

  scanf("%d", &N);

  int DP[N + 1];
  int t[N + 1];

  DP[0] = 0;
  t[0] = 0;

  for (int i=1; i<=N; i++) {
    scanf("%d", &n);

    // TODO: 다시 짜기
    t[i] = n;
    DP[i] = i < 2 ? t[i] : Max(Max(DP[i - 2] + t[i - 1] + n, n), DP[i - 1]);
  }

  for(int i=1; i<=N; i++) printf("%d ", DP[i]);

  return 0;
}

// 점화식을 생각해보자
// 10
//   10     -4     3     1      5     6     -35     12     21     -1
//   10     10    10    10     10    10      10     12     33     33
//                여기서 어떻게 처리할지 고민하면됨(10 + 3은 13인데 연속된 수가 아니라 10이어야함)

