#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <string>

using namespace std;

void uva_12503() {
	int tc, n, p, v, i, arr[100];
	string cmd;
	cin >> tc;
	while (tc--) {
		cin >> n;
		p = 0;
		for (i = 0; i < n; i++) {
			cin >> cmd;
			if (cmd.compare("SAME") == 0) {
				cin >> cmd;
				cin >> v;
				arr[i] = arr[v - 1];
			}
			else {
				arr[i] = cmd.compare("LEFT") == 0 ? -1 : 1;
			}
			p += arr[i];
		}
		cout << p << "\n";
	}
}
