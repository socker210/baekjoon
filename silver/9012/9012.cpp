#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	freopen("example.txt", "r", stdin);

	int T;
	char C[51], S[51];

	cin >> T;

	while(T--) {
		cin >> C;

		int top = -1;

		for (int i=0; C[i]; i++) {
			S[++top] = C[i];

			if (top > -1 && S[top - 1] == '(' && C[i] == ')') {
				top--;
				top--;
			}
		}

		cout << (top == -1 ? "YES" : "NO") << '\n';
	}

	return 0;
}