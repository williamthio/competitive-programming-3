#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <cmath>

using namespace std;

void uva_12157() {
	int tc, i, n, dur, mile, juice;
	cin >> tc;
	for (i = 1; i <= tc; i++) {
		cin >> n;
		mile = 0;
		juice = 0;
		while (n--) {
			cin >> dur;
			mile += (int)ceil((dur + 1) / 30.0) * 10;
			juice += (int)ceil((dur + 1) / 60.0) * 15;
		}
		cout << "Case " << i << ": ";
		if (mile < juice)
			cout << "Mile " << mile << "\n";
		else if (juice < mile)
			cout << "Juice " << juice << "\n";
		else
			cout << "Mile Juice " << mile << "\n";
	}
}
