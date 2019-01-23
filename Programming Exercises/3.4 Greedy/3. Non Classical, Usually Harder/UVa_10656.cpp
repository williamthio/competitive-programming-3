#include <iostream>

using namespace std;

void uva_10656() {
    int n;
    while (cin >> n, n) {
        bool start = true;
        int num;
        while (n--) {
            cin >> num;
            if (!num)
                continue;
            if (!start)
                cout << " ";
            start = false;
            cout << num;
        }
        if (start)
            cout << "0";
        cout << "\n";
    }
}
