#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void uva_12015() {
	int tc, i, j, v, max;
	string s;
	vector<string> urls;
	cin >> tc;
	for (i = 1; i <= tc; i++) {
		max = 0;
		for (j = 0; j < 10; j++) {
			cin >> s;
			cin >> v;
			if (max < v) {
				urls.clear();
				max = v;
				urls.push_back(s);
			}
			else if (max == v) {
				urls.push_back(s);
			}
		}
		cout << "Case #" << i << ":\n";
		for (auto it = urls.begin(); it != urls.end(); it++) {
			cout << *it << "\n";
		}
	}
}
