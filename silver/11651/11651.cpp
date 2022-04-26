#include <iostream>

using namespace std;

struct Point {
  int x;
  int y;
};

void swap(Point* p1, Point* p2) {
  Point t = *p1;

  *p1 = *p2;
  *p2 = t;
}

int main() {
  int N;

  scanf("%d", &N);

  Point p[N];

  for (int i=0; i<N; i++) {
    Point t;

    scanf("%d %d", &t.x, &t.y);

    p[i] = t;
  }

  for (int i=0; i<N - 1; i++) {
    for (int j=i + 1; j<N; j++) {
      if (p[j].y < p[i].y) {
        swap(&p[i], &p[j]);
      } else if (p[j].y == p[i].y && p[j].x < p[i].x) {
        swap(&p[i], &p[j]);
      }
    }
  }

  for (int i=0; i<N; i++) {
    cout << p[i].x << " " << p[i].y << endl;
  }

  return 0;
}