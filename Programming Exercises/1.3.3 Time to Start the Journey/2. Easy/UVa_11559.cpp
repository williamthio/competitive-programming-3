#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>

using namespace std;

void uva_11559() {
	int num, budget, h, w, i, price, available, total;
	while (cin >> num, !cin.fail()) {
		cin >> budget;
		cin >> h;
		cin >> w;
		total = 200 * 10000 + 1;
		while (h--) {
			cin >> price;
			for (i = 0; i < w; i++) {
				cin >> available;
				if (num <= available && total > price * num)
					total = price * num;
			}
		}
		if (total <= budget)
			cout << total << "\n";
		else
			cout << "stay home\n";
	}
}
