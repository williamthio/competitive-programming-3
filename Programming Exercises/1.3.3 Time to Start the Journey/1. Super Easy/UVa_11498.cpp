#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>

using namespace std;

void uva_11498() {
	int n, divx, divy, posx, posy;
	while (cin >> n, n) {
		cin >> divx;
		cin >> divy;
		while (n--) {
			cin >> posx;
			cin >> posy;
			if (divx == posx || divy == posy) {
				cout << "divisa";
			}
			else if (divy < posy) {
				if (divx < posx) {
					cout << "NE";
				}
				else {
					cout << "NO";
				}
			}
			else {
				if (divx < posx) {
					cout << "SE";
				}
				else {
					cout << "SO";
				}
			}
			cout << endl;
		}
	}
}
