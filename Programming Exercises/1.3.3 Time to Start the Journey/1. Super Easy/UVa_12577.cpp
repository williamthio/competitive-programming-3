#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <string>

using namespace std;

void uva_12577() {
	int tc = 1;
	string line;
	while (getline(cin, line)) {
		if (line.size() == 1 && line[0] == '*') {
			break;
		}
		cout << "Case " << tc++ << ": ";
		if (line.compare("Hajj") == 0)
			cout << "Hajj-e-Akbar\n";
		else
			cout << "Hajj-e-Asghar\n";
	}
}
