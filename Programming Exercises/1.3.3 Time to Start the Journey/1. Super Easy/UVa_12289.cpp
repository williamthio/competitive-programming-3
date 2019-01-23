#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <string>
#include <limits>

using namespace std;

void uva_12289() {
	int tc, n;
	string word;
	cin >> tc;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	while (tc--) {
		getline(cin, word);
		n = word.length();
		if (n == 5) {
			cout << "3\n";
		}
		else if (n == 3) {
			if (word[0] == 'o' && (word[1] == 'n' || word[2] == 'e')
				|| word[1] == 'n' && (word[0] == 'o' || word[2] == 'e')
				|| word[2] == 'e' && (word[0] == 'o' || word[1] == 'n'))
				cout << "1\n";
			else
				cout << "2\n";
		}
	}
}
