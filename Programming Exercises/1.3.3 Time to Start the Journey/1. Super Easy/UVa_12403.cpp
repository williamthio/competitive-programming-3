#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <string>

using namespace std;

void uva_12403() {
	int n, amount, total = 0;
	string action;
	cin >> n;
	while (n--) {
		cin >> action;
		if (action.compare("donate") == 0) {
			cin >> amount;
			total += amount;
		}
		else
			cout << total << "\n";
	}
}
