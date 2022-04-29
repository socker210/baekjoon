#include <iostream>

using namespace std;

// 점화식
// n == 0, 0
// n == 1, 1
// F(n - 1) + F(n - 2), n > 2

int recursion(int* cnt, int n) {
  (*cnt)++;

  if (n == 0) return 0;
  if (n == 1) return 1;

  return recursion(cnt, n - 1) + recursion(cnt, n - 2);
}

void dp() {

}

int main() {
  int N;
  int recursive_cnt = 0;
  int dp_cnt = 0;

  scanf("%d", &N);

  recursion(&recursive_cnt, N);

  printf("%d %d", recursive_cnt, dp_cnt);

  return 0;
}
