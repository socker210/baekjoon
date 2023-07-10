#include <iostream>

using namespace std;

int main() {
	int h, m, t;

	cin >> h >> m >> t;

	cout << ((h+(m+t)/60)%24) << ' ' << ((m+t)%60);
	
	return 0;
}