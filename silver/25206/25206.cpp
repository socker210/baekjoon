#include <iostream>

using namespace std;

int main() {
	char sub[51], lev[3];
	float point, subPoint, sum = 0.0, pointSum = 0.0;

	for (int i=0; i<20; i++) {
		cin >> sub >> point >> lev;

		if (lev[0] == 'P') continue;

		switch(lev[0]) {
			case 'A':
				subPoint = 4.0;
				break;
			case 'B':
				subPoint = 3.0;
				break;
			case 'C':
				subPoint = 2.0;
				break;
			case 'D':
				subPoint = 1.0;
				break;
			default:
				subPoint = 0.0;
				break;
		}

		if (lev[1] == '+') subPoint += 0.5;
		
		pointSum += point;
		sum += point * subPoint;
	}

	cout << sum / pointSum;

	return 0;
}