#include <iostream>

using namespace std;

int main() {
	int chicken, coke, beer;

	scanf("%d %d %d", &chicken, &coke, &beer);

	int a = coke / 2 + beer;

	printf("%d", a > chicken ? chicken : a);

	return 0;
}