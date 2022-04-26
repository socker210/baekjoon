#include <iostream>

using namespace std;

struct Point {
  int x;
  int y;
};

int main() {
  int N;

  scanf("%d", &N);

  Point p[N];

  for (int i=0; i<N; i++) {
    Point t;

    scanf("%d %d", &t.x, &t.y);

    p[i] = t;
  }

  // TODO: y ASC, x ASC

  for (int i=0; i<N; i++) {
    cout << p[i].x << " " << p[i].y << endl;
  }

  return 0;
}