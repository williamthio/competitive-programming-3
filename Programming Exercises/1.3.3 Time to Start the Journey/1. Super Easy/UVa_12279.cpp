#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>

using namespace std;

void uva_12279() {
	int n, e, b, tc = 1;
	while (cin >> n, n) {
		b = 0;
		while (n--) {
			cin >> e;
			b += e > 0 ? 1 : -1;
		}
		cout << "Case " << tc++ << ": " << b << "\n";
	}
}
