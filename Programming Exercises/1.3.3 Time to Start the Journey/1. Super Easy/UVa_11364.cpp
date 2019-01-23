#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>

using namespace std;

void uva_11364() {
	int tc, n, l, r, curr;
	cin >> tc;
	while (tc--) {
		cin >> n;
		l = 100;
		r = -1;
		while (n--) {
			cin >> curr;
			if (l > curr)
				l = curr;
			if (r < curr)
				r = curr;
		}
		cout << 2 * (r - l) << endl;
	}
}
