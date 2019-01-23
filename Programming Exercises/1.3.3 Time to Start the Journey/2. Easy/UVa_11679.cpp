#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <unordered_map>

using namespace std;

void uva_11679() {
	int b, n, r, from, to, v, i;
	bool bail;
	unordered_map<int, int> reserves;
	while (cin >> b, cin >> n, b && n) {
		reserves.clear();
		for (i = 1; i <= b; i++) {
			cin >> r;
			reserves[i] += r;
		}
		while (n--) {
			cin >> from;
			cin >> to;
			cin >> v;
			reserves[from] -= v;
			reserves[to] += v;
		}
		bail = false;
		for (auto it = reserves.begin(); it != reserves.end(); it++)
			if (it->second < 0)
				bail = true;
		cout << (bail ? "N" : "S") << "\n";
	}
}
