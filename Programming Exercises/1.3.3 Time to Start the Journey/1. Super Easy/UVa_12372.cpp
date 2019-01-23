#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <string>

using namespace std;

void uva_12372() {
	int tc, i, j, l;
	string output;
	cin >> tc;
	for (i = 1; i <= tc; i++) {
		output = "good";
		for (j = 0; j < 3; j++) {
			cin >> l;
			if (l > 20)
				output = "bad";
		}
		cout << "Case " << i << ": " << output << "\n";
	}
}
