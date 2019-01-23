#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>

using namespace std;

void uva_11764() {
	int tc, n, i, currHeight, high, low, next;
	cin >> tc;
	for (i = 1; i <= tc; i++) {
		cin >> n;
		high = 0;
		low = 0;
		currHeight = -1;
		while (n--) {
			cin >> next;
			if (currHeight == -1) {
				currHeight = next;
				continue;
			}
			if (currHeight < next)
				high++;
			else if (currHeight > next)
				low++;
			currHeight = next;
		}
		cout << "Case " << i << ": " << high << " " << low << "\n";
	}
}
