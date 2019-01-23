#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <string>

using namespace std;

void uva_00272() {
	char c;
	bool isLeft = true;
	string output = "";
	while (cin.get(c)) {
		if (c == '"') {
			output += isLeft ? "``" : "''";
			isLeft = !isLeft;
		}
		else {
			output += c;
		}
	}
	cout << output;
}
