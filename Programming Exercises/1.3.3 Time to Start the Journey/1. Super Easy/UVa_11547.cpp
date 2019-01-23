#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <cmath>

using namespace std;

void uva_11547() {
	int tc, n;
	cin >> tc;
	while (tc--) {
		cin >> n;
		cout << abs(((n * 567 / 9 + 7492) * 235 / 47 - 498) % 100) / 10 << endl;
	}
}
