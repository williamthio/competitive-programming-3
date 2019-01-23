#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>

using namespace std;

void uva_11172() {
	int tc, a, b;
	cin >> tc;
	while (tc--) {
		cin >> a;
		cin >> b;
		cout << (a < b ? '<' : (a > b ? '>' : '=')) << endl;
	}
}
