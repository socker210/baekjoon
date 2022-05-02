#include <iostream>

using namespace std;

int main() {
  int N;

  scanf("%d", &N);

  int cnt = 0;
  int n = N;

  while(true) {
    int r5 = n % 5;
    
    if (r5 == 0) {
      cnt += (N - cnt * 3) / 5;

      break;
    }

    if (n < 0) {
      cnt = -1;

      break;
    }

    n -= 3;

    cnt++;
  }

  printf("%d", cnt);

  return 0;
}