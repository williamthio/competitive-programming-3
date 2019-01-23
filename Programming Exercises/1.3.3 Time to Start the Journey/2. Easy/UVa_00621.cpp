#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <limits>
#include <string>

using namespace std;

void uva_00621() {
	int n, len;
	string s;
	cin >> n;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	while (n--) {
		getline(cin, s);
		len = s.length();
		if (len == 1) {
			if (s[0] == '1' || s[0] == '4')
				cout << "+\n";
		}
		else if (len == 2) {
			if (s[0] == '7' && s[1] == '8')
				cout << "+\n";
		}
		else if (s[len - 2] == '3' && s[len - 1] == '5') {
			cout << "-\n";
		}
		else if (s[0] == '9' && s[len - 1] == '4') {
			cout << "*\n";
		}
		else if (len > 3 && s[0] == '1' && s[1] == '9' && s[2] == '0') {
			cout << "?\n";
		}
		else {
			cout << "?\n";
		}
	}
}
