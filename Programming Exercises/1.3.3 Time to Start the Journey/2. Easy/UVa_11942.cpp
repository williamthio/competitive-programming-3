#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <limits>

using namespace std;

void uva_11942() {
	int tc, i, l, prev;
	bool ordered, shortToLong;
	cin >> tc;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Lumberjacks:\n";
	while (tc--) {
		prev = -1;
		ordered = true;
		for (i = 0; i < 10; i++) {
			cin >> l;
			if (i > 1 && (shortToLong && prev >= l || !shortToLong && prev <= l)) {
				ordered = false;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				break;
			}
			else if (i == 1) {
				shortToLong = prev < l;
			}
			prev = l;
		}
		cout << (ordered ? "Ordered" : "Unordered") << "\n";
	}
}
