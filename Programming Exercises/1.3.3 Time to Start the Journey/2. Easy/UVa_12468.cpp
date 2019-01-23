#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>

using namespace std;

void uva_12468() {
	int a, b, up, down;
	while (cin >> a, cin >> b, a != -1 && b != -1) {
		if (a == b) {
			cout << "0\n";
			continue;
		}
		else if (a < b) {
			up = b - a;
			down = a + 100 - b;
		}
		else {
			up = b + 100 - a;
			down = a - b;
		}
		cout << (up < down ? up : down) << "\n";
	}
}
