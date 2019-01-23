#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <string>

using namespace std;

void uva_12250() {
	string word;
	int tc = 1;
	while (getline(cin, word)) {
		if (word.length() == 1 && word[0] == '#')
			break;
		cout << "Case " << tc++ << ": ";
		if (word.compare("HELLO") == 0)
			cout << "ENGLISH";
		else if (word.compare("HOLA") == 0)
			cout << "SPANISH";
		else if (word.compare("HALLO") == 0)
			cout << "GERMAN";
		else if (word.compare("BONJOUR") == 0)
			cout << "FRENCH";
		else if (word.compare("CIAO") == 0)
			cout << "ITALIAN";
		else if (word.compare("ZDRAVSTVUJTE") == 0)
			cout << "RUSSIAN";
		else
			cout << "UNKNOWN";
		cout << "\n";
	}
}
