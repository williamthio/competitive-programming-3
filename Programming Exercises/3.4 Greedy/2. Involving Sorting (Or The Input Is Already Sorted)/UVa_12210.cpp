#include <iostream>

using namespace std;

void uva_12210() {
    int b, s, ci = 0;
    while (cin >> b, cin >> s, b || s) {
        int bachelors[10000], spinsters[10000];
        for (int i = 0; i < b; i++)
            cin >> bachelors[i];
        for (int i = 0; i < s; i++)
            cin >> spinsters[i];

        if (b <= s) {
            cout << "Case " << ++ci << ": 0\n";
        }
        else {
            int min = 61;
            for (int i = 0; i < b; i++) {
                if (min > bachelors[i])
                    min = bachelors[i];
            }
            cout << "Case " << ++ci << ": " << (b - s) << " " << min << "\n";
        }
    }
}
