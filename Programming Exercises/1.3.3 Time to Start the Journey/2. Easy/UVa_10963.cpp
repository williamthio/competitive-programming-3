#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <cmath>

using namespace std;

void uva_10963() {
	int tc, cc, gap, north, south;
	bool canBeClosed;
	cin >> tc;
	while (tc--) {
		cin >> cc;
		gap = -1;
		canBeClosed = true;
		while (cc--) {
			cin >> north;
			cin >> south;
			if (gap == -1) {
				gap = abs(north - south);
				continue;
			}
			else if (abs(north - south) != gap) {
				canBeClosed = false;
			}
		}
		cout << (canBeClosed ? "yes" : "no") << "\n" << (tc > 0 ? "\n" : "");
	}
}
