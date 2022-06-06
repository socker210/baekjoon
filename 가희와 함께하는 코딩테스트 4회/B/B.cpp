#include <iostream>

using namespace std;

char p_time[6];

int to_int(char a, char b) {
	return (a - '0') * 10 + (b - '0');
}

void to_p_time(int h, int m) {
	p_time[0] = (h > 9 ? h / 10 : 0) + '0';
	p_time[1] = (h > 9 ? h % 10 : h) + '0';
	p_time[2] = ':';
	p_time[3] = (m > 9 ? m / 10 : 0) + '0';
	p_time[4] = (m > 9 ? m % 10 : m) + '0';
}

int p_time_to_idx() {
	return to_int(p_time[0], p_time[1]) / 2;
}

void add_evt_item(char* evt_item) {
	int add_h = 0, add_m = 0;

	if (evt_item[2] == 'M') {
		int tot_m = to_int(evt_item[0], evt_item[1]) + to_int(p_time[3], p_time[4]);
		add_h = tot_m / 60;
		add_m = tot_m % 60;
	} else {
		add_h = to_int('0', evt_item[0]);
		add_m = to_int(p_time[3], p_time[4]);
	}

	int n_h = (add_h + to_int(p_time[0], p_time[1])) % 12;
	int n_m = add_m;

	to_p_time(n_h, n_m);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	freopen("examples.txt", "r", stdin);

	int pct[6], seal[6] = {0,}, tot_evt_cnt, sum = 0;
	char evt_p_time[7], evt_item[6];

	cin >> p_time;

	for (int i=0; i<6;i ++) cin >> pct[i];

	cin >> tot_evt_cnt;

	while(tot_evt_cnt--) {
		cin >> evt_p_time >> evt_item;

		if (evt_item[0] == '^') seal[p_time_to_idx()] = 1;
		else add_evt_item(evt_item);
	}

	for (int i=0; i<6; i++) sum += (seal[i] == 1 ? 0 : pct[i]);

	cout << (sum > 100 ? 100 : sum);

	return 0;
}