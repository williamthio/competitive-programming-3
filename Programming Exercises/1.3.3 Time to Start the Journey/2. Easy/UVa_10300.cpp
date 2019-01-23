#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>

using namespace std;

void uva_10300() {
	int tc, fn, s, na, ef;
	unsigned long long total;
	cin >> tc;
	while (tc--) {
		cin >> fn;
		total = 0;
		while (fn--) {
			cin >> s;
			cin >> na;
			cin >> ef;
			if (na == 0)
				continue;
			total += (unsigned long long)s * ef;
		}
		cout << total << "\n";
	}
}
