#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

void uva_12554() {
	int n, i, r;
	vector<string> names;
	string lyric[] = {
		"Happy", "birthday", "to", "you",
		"Happy", "birthday", "to", "you",
		"Happy", "birthday", "to", "Rujia",
		"Happy", "birthday", "to", "you"
	};
	cin >> n;
	names.resize(n);
	r = (int)ceil(n / 16.0);
	for (i = 0; i < n; i++)
		cin >> names[i];
	for (i = 0; i < 16 * r; i++)
		cout << names[i % n] << ": " << lyric[i % 16] << "\n";
}
