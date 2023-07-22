#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
	string N;
	int B, i = 0, ans = 0;

	cin >> N >> B;

	while(N[i]) {
		int num = N[i] >= 'A' ? N[i] - 'A' + 10 : N[i] - '0';
		
		ans += num * pow(B, N.length() - i - 1);

		i++;
	}

	cout << ans;

	return 0;
}
