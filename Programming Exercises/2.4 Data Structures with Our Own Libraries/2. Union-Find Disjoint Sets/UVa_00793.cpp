#include <iostream>
#include <vector>
#include <functional>
#include <limits>
#include <sstream>

using namespace std;

void uva_00793() {
    int tc;
    cin >> tc;
    bool start = true;
    while (tc--) {
        if (start)
            start = false;
        else
            cout << "\n";

        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        vector<int> network(n);
        for (int i = 0; i < n; i++)
            network[i] = -1;

        function<int(int)> find = [&](int i) -> int {
            if (network[i] < 0)
                return i;
            network[i] = find(network[i]);
            return network[i];
        };

        int c = 0;
        int nc = 0;
        char cmd;
        while (cmd = cin.get(), !cin.fail() && cmd != '\n') {
            int a;
            int b;
            cin >> a;
            cin >> b;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            a = find(a - 1);
            b = find(b - 1);

            if (cmd == 'c') {
                if (a == b)
                    continue;
                if (network[a] < network[b]) {
                    network[a] += network[b];
                    network[b] = a;
                }
                else {
                    network[b] += network[a];
                    network[a] = b;
                }
            }
            else {
                if (a == b)
                    c++;
                else
                    nc++;
            }
        }

        cout << c << "," << nc << "\n";
    }
}
