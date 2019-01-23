#include <iostream>
#include <unordered_map>

using namespace std;

void uva_12356() {
    int s, b;
    while (cin >> s, s) {
        cin >> b;
        unordered_map<int, int> rtl, ltr;
        while (b--) {
            int l, r;
            cin >> l;
            cin >> r;

            if (rtl[l - 1] != 0)
                rtl[r] = rtl[l - 1];
            else
                rtl[r] = l;
            if (ltr[r + 1])
                rtl[ltr[r + 1]] = rtl[r];

            if (ltr[r + 1] != 0)
                ltr[l] = ltr[r + 1];
            else
                ltr[l] = r;
            if (rtl[l - 1])
                ltr[rtl[l - 1]] = ltr[l];

            int ls = l - 1;
            while (rtl[ls])
                ls = rtl[ls] - 1;

            int rs = r + 1;
            while (ltr[rs])
                rs = ltr[rs] + 1;


            if (ls < 1)
                cout << "* ";
            else
                cout << ls << " ";
            if (rs > s)
                cout << "*\n";
            else
                cout << rs << "\n";
        }
        cout << "-\n";
    }
}
