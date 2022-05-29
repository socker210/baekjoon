#include <iostream>

using namespace std;

int main() {
	int a, b, c, r;

	scanf("%d %d %d", &a, &b, &c);

	r = a * b * c;

	int cnt[10] = {0,};

	while(r != 0) {
		int mod = r % 10;

		cnt[mod]++;

		r = (r - mod) / 10;
	}

	for (int i=0; i<10; i++) printf("%d\n", cnt[i]);

	return 0;
}