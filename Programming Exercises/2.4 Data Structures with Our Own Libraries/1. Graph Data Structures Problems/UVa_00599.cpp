#include <iostream>
#include <string>
#include <functional>

using namespace std;

void uva_00599() {
    string line;
    int tc;
    cin >> tc;
    cin.get();
    while (tc--) {
        int v[26];
        for (int i = 0; i < 26; i++)
            v[i] = -1;

        function<int(int)> find = [&](int i) -> int {
            if (v[i] < 0)
                return i;
            v[i] = find(v[i]);
            return v[i];
        };

        while (getline(cin, line) && !line.empty() && line[0] != '*') {
            int a = line[1] - 'A';
            int b = line[3] - 'A';
            a = find(a);
            b = find(b);
            if (a == b)
                continue;
            if (v[a] < v[b]) {
                v[a] += v[b];
                v[b] = a;
            }
            else {
                v[b] += v[a];
                v[a] = b;
            }
        }

        int tree = 0;
        int acorn = 0;
        getline(cin, line);
        for (int i = 0, n = line.size(); i < n; i += 2) {
            int c = line[i] - 'A';
            if (v[c] == -1)
                acorn++;
            else if (v[c] < -1)
                tree++;
        }

        cout << "There are " << tree << " tree(s) and " << acorn << " acorn(s).\n";
    }
}
