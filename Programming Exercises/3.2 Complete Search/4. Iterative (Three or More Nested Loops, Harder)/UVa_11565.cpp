#include <iostream>
#include <functional>

using namespace std;

void uva_11565() {
    int tc;
    cin >> tc;
    while (tc--) {
        int a, b, c;
        cin >> a;
        cin >> b;
        cin >> c;

        bool found = false;

        auto check = [&](int x, int y, int z) -> bool {
            if (x * y * z == b && x * x + y * y + z * z == c) {
                found = true;
                cout << x << " " << y << " " << z << "\n";
            }
            return found;
        };
        for (int x = -100; !found && x < 0; x++) {
            for (int y = x + 1; y < 0; y++) {
                int z = a - x - y;
                if (check(x, y, z))
                    break;
            }
        }
        if (!found) {
            for (int x = 1; !found && x <= a / 3; x++) {
                for (int y = x + 1; y <= (a + 1) / 2 - (x / 2 + 1); y++) {
                    int z = a - x - y;
                    if (z == y)
                        continue;
                    if (check(x, y, z))
                        break;
                }
            }
        }

        //int x, y, z;
        //for (x = -100; x <= 100; x++) {
        //    for (y = -100; y <= 100; y++) {
        //        for (z = -100; z <= 100; z++) {
        //            if (y != x && z != x && z != y
        //                && x + y + z == a
        //                && x * y * z == b
        //                && x * x + y * y + z * z == c) {
        //                if (!found)
        //                    printf("%d %d %d\n", x, y, z);
        //                found = true;
        //            }
        //        }
        //    }
        //}

        if (!found)
            cout << "No solution.\n";
    }
}
