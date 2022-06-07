#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	freopen("example.txt", "r", stdin);

	char str[101], bracket[101];
	
	while(true) {
		cin.getline(str, 101);

		if (str[0] == '.') break;

		int top = -1;

		for (int i=0; str[i]; i++) {
			char c = str[i];

			if (c != '(' && c != ')' && c != '[' && c != ']') continue;

			bracket[++top] = c;

			if ((c == ']' && top > 0 && bracket[top - 1] == '[') || (c == ')' && top > 0 && bracket[top - 1] == '(')) top -= 2;
		}

		cout << (top == -1 ? "yes" : "no") << '\n';
	}

	return 0;
}