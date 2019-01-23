#include <iostream>
#include <set>
#include <functional>
#include <queue>

using namespace std;

void uva_00978() {
    int tc;
    cin >> tc;
    for (int ci = 0; ci < tc; ci++) {
        if (ci > 0)
            cout << "\n";

        int b, sg, sb;
        cin >> b;
        cin >> sg;
        cin >> sb;

        multiset<int, greater<int>> ga, ba;
        int pow;
        while (sg--) {
            cin >> pow;
            ga.insert(pow);
        }
        while (sb--) {
            cin >> pow;
            ba.insert(pow);
        }

        int over = false;
        queue<int> gs, bs;
        while (!over) {
            for (int i = 0; i < b; i++) {
                if (ga.empty() || ba.empty())
                    break;

                int g = *ga.begin();
                int b = *ba.begin();

                ga.erase(ga.begin());
                ba.erase(ba.begin());

                if (g > b)
                    gs.push(g - b);
                else if (g < b)
                    bs.push(b - g);
            }

            while (!gs.empty()) {
                ga.insert(gs.front());
                gs.pop();
            }

            while (!bs.empty()) {
                ba.insert(bs.front());
                bs.pop();
            }

            if (ga.empty() || ba.empty())
                break;
        }

        if (ga.empty() && ba.empty()) {
            cout << "green and blue died\n";
            continue;
        }

        cout << (ga.empty() ? "blue" : "green") << " wins\n";
        auto winner = ga.empty() ? ba : ga;
        for (int pow : winner)
            cout << pow << "\n";
    }
}
