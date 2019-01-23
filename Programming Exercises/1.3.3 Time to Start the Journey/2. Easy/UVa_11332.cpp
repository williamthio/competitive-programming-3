#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <string>

using namespace std;

void uva_11332() {
	string s;
	int n, count;
	while (getline(cin, s)) {
		if (s.size() == 1 && s[0] == '0')
			break;
		while (n = s.size(), n > 1) {
			count = 0;
			while (n--)
				count += s[n] - '0';
			s = to_string(count);
		}
		cout << s << "\n";
	}
}
