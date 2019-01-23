#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <cmath>

using namespace std;

void uva_10550() {
	int a, b, c, d, i;
	int rotation;
	while (scanf("%d %d %d %d", &a, &b, &c, &d), a || b || c || d) {
		rotation = 1080;
		for (i = a; i != b; i--) {
			if (i == 0) {
				i = 40;
				if (b == i) break;
			}
			rotation += 9;
		}
		for (i = b; i != c; i++) {
			if (i == 40) {
				i = 0;
				if (c == i) break;
			}
			rotation += 9;
		}
		for (i = c; i != d; i--) {
			if (i == 0) {
				i = 40;
				if (d == i) break;
			}
			rotation += 9;
		}
		cout << rotation << endl;
	}
}
