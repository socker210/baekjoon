#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	freopen("examples.txt", "r", stdin);

	int N;

	cin >> N;

	int n[N], t, top = -1, sum = 0;

	while (N--) {
		cin >> t;
		
		if (t != 0) {
			top += 1;

			n[top] = t;
			sum += n[top];
		} else {
			sum -= n[top];
			top -= 1;
		}
	}

	cout << sum;
}