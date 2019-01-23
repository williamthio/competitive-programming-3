#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <cmath>

using namespace std;

void uva_11044() {
	int tc, n, m, out;
	cin >> tc;
	while (tc--) {
		cin >> n;
		cin >> m;
		out = (int)(ceil((n - 2) / 3.0) * ceil((m - 2) / 3.0));
		cout << out << endl;
	}
}
