#include <iostream>

using namespace std;

void sort() {
  // TODO: 퀵정렬 하기
}

int main() {
  int N;
  int n[N];

  scanf("%d", &N);

  for (int i=0; i<N; i++) scanf("%d", &n[i]);

  sort();

  for (int i=0; i<N; i++) cout << n[i] << endl;

  return 0;
}
