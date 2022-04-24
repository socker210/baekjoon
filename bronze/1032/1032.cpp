#include <iostream>
#include <string>

using namespace std;

int main() {
	int N;

	cin >> N;

	string str[N];

	for (int i=0; i<N; i++) {
		cin >> str[i];
	}

	int len = str[0].length();
	char res[len];

	for (int i=0; i<len; i++) {
		char t;

		for (int j=0; j<N; j++)	{
			t = j == 0 ? str[j][i] : t == str[j][i] ? t : '?';
		}

		res[i] = t;
	}

	for (int i=0;i<len;i++) {
		cout << res[i];
	}

	return 0;
}
