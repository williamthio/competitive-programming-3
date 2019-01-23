#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

void uva_00119() {
	int n, i, gift, gn, v;
	bool start = true;
	string name, gr;
	vector<string> names;
	unordered_map<string, int> net;
	while (cin >> n, !cin.fail()) {
		if (!start)
			cout << "\n";
		start = false;
		names.clear();
		net.clear();
		for (i = 0; i < n; i++) {
			cin >> name;
			names.push_back(name);
			net[name] = 0;
		}
		for (i = 0; i < n; i++) {
			cin >> name;
			cin >> gift;
			cin >> gn;
			if (gn == 0) continue;
			net[name] -= gift - (gift % gn);
			v = gift / gn;
			while (gn--) {
				cin >> gr;
				net[gr] += v;
			}
		}
		for (i = 0; i < n; i++) {
			name = names[i];
			cout << name << " " << net[name] << "\n";
		}
	}
}
