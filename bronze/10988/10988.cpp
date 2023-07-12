#include <iostream>

using namespace std;

int main() {
	char str[101];
	int len = 0, res = 1;

	cin >> str;

	while(str[len]) len++;
	
	for (int i=len - 1; i>=0; i--) {
		if (str[i] != str[len - i - 1]) {
			res = 0;
			break;
		}
	}

	cout << res;

	return 0;
}