#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void uva_11727() {
	int tc, a, b, c;
	vector<int> n;
	cin >> tc;
	for (int i = 1; i <= tc; i++) {
		n.clear();
		cin >> a;
		cin >> b;
		cin >> c;
		n.push_back(a);
		n.push_back(b);
		n.push_back(c);
		sort(n.begin(), n.end());
		cout << "Case " << i << ": " << n[1] << "\n";
	}
}
