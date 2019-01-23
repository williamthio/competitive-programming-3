#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <queue>
#include <utility>

using namespace std;

void uva_10114() {
	int months, dn, i, s;
	double ppm, dp, tbp, cv, currDep;
	queue<pair<int, double>> dep;
	while (cin >> months, months >= 0) {
		cin >> dp;
		cin >> tbp;
		cin >> dn;
		s = dep.size();
		while (s--)
			dep.pop();
		while (dn--) {
			pair<int, double> m;
			cin >> m.first;
			cin >> m.second;
			dep.push(m);
		}
		ppm = tbp / months;
		cv = tbp + dp;
		for (i = 0; i <= months; i++) {
			if (!dep.empty() && dep.front().first == i) {
				currDep = dep.front().second;
				dep.pop();
			}
			cv -= cv * currDep;
			if (i > 0) {
				tbp -= ppm;
			}
			if (tbp < cv) {
				cout << i << " month" << (i == 1 ? "\n" : "s\n");
				break;
			}
		}
	}
}
