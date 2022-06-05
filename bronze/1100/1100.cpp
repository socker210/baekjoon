#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	freopen("examples.txt", "r", stdin);

	int cnt = 0;
	char n;

	for (int i=1; i<=8; i++)
		for (int j=1; j<=8; j++) {
			cin >> n;

			if (j % 2 == (i % 2 == 0 ? 1 : 0)) continue;

			cnt += (n == 'F' ? 1 : 0);
		}

	cout << cnt;
}