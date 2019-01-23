#include <iostream>
#include <string>

using namespace std;

void uva_11507() {
    int l;
    string s, curr;
    while (cin >> l, l) {
        curr = "+x";
        while (l-- > 1) {
            cin >> s;
            if (s[0] == 'N' && s[1] == 'o')
                continue;
            if (curr[1] == 'x') {
                if (curr[0] == '-')
                    s[0] = s[0] == '+' ? '-' : '+';
                curr = s;
            }
            else if (curr[1] == s[1]) {
                if (curr[0] == s[0])
                    curr = "-x";
                else
                    curr = "+x";
            }
        }
        cout << curr << "\n";
    }
}
