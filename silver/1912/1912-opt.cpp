#include <iostream>

#define Max(a,b) (a>b?a:b)

int main() {
  std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);

  int N, n, sum = 0, ans = -1001;

  std::cin >> N;

  for (int i=0; i<N; i++) {
    std::cin >> n;

    sum = Max(sum + n, n);
    ans = Max(sum, ans);
  }

  std::cout << ans;

  return 0;
}
