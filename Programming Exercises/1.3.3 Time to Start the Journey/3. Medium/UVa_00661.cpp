#include <iostream>
#include <bitset>

using namespace std;

void uva_00661() {
    int n, m, c, da[20], i, curr, max, d, seq = 0;
    bitset<20> states;
    bool state, blown;
    while (cin >> n, cin >> m, cin >> c, n && m && c) {
        max = 0;
        states.reset();
        blown = false;
        curr = 0;
        for (i = 0; i < n; i++)
            cin >> da[i];
        while (m--) {
            cin >> d;
            state = !states[d - 1];
            states[d - 1] = state;
            if (state) {
                curr += da[d - 1];
                if (curr > c)
                    blown = true;
                if (max < curr)
                    max = curr;
            }
            else {
                curr -= da[d - 1];
            }
        }
        cout << "Sequence " << ++seq << "\n";
        if (blown)
            cout << "Fuse was blown.\n\n";
        else
            cout << "Fuse was not blown.\nMaximal power consumption was " << max << " amperes.\n\n";
    }
}
