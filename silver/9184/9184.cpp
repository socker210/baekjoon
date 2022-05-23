#include <iostream>
#define Output(a,b,c,res) printf("w(%d, %d, %d) = %d\n", a, b, c, res)

using namespace std;

int DP[51][51][51];

int solve(int a, int b, int c) {
	if (DP[a][b][c] != 0) return DP[a][b][c];

	if (a <= 0 || b <= 0 || c <= 0) {
		DP[a][b][c] = 1;
	} else if (a > 20 || b > 20 || c > 20) {
		DP[a][b][c] = solve(20, 20, 20);
	} else {
		DP[a][b][c] = a < b && b < c ?
			solve(a, b, c - 1) + solve(a, b - 1, c - 1) - solve(a, b - 1, c) :
			solve(a - 1, b, c) + solve(a - 1, b - 1, c) + solve(a - 1, b, c - 1) - solve(a - 1, b - 1, c - 1);
	}

	return DP[a][b][c];
}

int main() {
	int a, b, c;

	while (true) {
		scanf("%d %d %d", &a, &b, &c);

		if (a == -1 && b == -1 && c == -1) break;

		if (a <= 0 || b <= 0 || c <= 0) {
			Output(a, b ,c, 1);

			continue;
		}
		
		solve(a, b, c);

		Output(a, b, c, DP[a][b][c]);
	}

	return 0;
}