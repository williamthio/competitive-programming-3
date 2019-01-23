#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>

using namespace std;

void uva_11799() {
	int tc, i, n, c, max;
	cin >> tc;
	for (i = 1; i <= tc; i++) {
		cin >> n;
		max = 0;
		while (n--) {
			cin >> c;
			if (max < c)
				max = c;
		}
		cout << "Case " << i << ": " << max << "\n";
	}
}
