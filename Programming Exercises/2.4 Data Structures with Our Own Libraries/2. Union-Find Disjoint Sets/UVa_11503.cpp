#include <iostream>
#include <string>
#include <unordered_map>
#include <functional>

using namespace std;

void uva_11503() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;

        unordered_map<string, bool> names;
        unordered_map<string, string> network;
        unordered_map<string, int> weights;
        auto addName = [&](string name) {
            if (!names[name]) {
                names[name] = true;
                network[name] = "";
                weights[name] = 1;
            }
        };
        function<string(string)> find = [&](string name) -> string {
            if (network[name].empty())
                return name;
            network[name] = find(network[name]);
            return network[name];
        };

        while (n--) {
            string a, b;
            cin >> a;
            cin >> b;
            addName(a);
            addName(b);
            a = find(a);
            b = find(b);

            if (a.compare(b) == 0) {
                cout << weights[a] << "\n";
                continue;
            }

            if (weights[a] > weights[b]) {
                weights[a] += weights[b];
                network[b] = a;
                cout << weights[a] << "\n";
            }
            else {
                weights[b] += weights[a];
                network[a] = b;
                cout << weights[b] << "\n";
            }
        }
    }
}
