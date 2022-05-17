#include <iostream>

using namespace std;

#define Max(a,b) (a>b?a:b)

int INPUT[10001];
int DP[10001];

int main() {
  int N;

  scanf("%d", &N);

  for (int i=1; i<=N; i++) {
    scanf("%d", &INPUT[i]);

    DP[i] = i < 3 ? INPUT[i - 1] + INPUT[i] :
            INPUT[i] == 0 ? DP[i - 1] :
            Max(INPUT[i] + INPUT[i - 1] + DP[i - 3], INPUT[i] + DP[i - 2]);
  }

  int M = DP[1];

  for (int i=1; i<=N; i++) M = M > DP[i] ? M : DP[i];

  printf("%d", M);

  return 0;
}

// 연속해서 포도주를 안마셔도 된다
// 6, 10, 13, 9, 8, 1
// 첫 번째, 두 번째, 네 번째, 다섯 번째
// 33

// INPUT[i] + INPUT[i - 1] + DP[i - 3]
// 

// 6, 10, 13, 9, 8, 1

// 6 10 = 16, 3
// 10 13 = 23, 1
// 6 13 = 19, 2

// 6 10 9 = 25, 2
// 6 13 9 = 28, 1
// 10 9 = 19, 5
// 10 13 = 23, 3
// 13 9 = 21, 4



// 6을 마셔야하는 경우, 
// 10을 마셔야하는 경우,
// 13을 마셔야하는 경우,
// 9를 마셔야하는 경우,
// 8을 마셔야하는 경우,
// 1을 마셔야하는 경우,