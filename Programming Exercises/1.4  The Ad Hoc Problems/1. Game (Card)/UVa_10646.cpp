#include <iostream> 
#include <string>
#include <vector>

using namespace std;

void uva_10646() {
    int tc;
    cin >> tc;
    for (int c = 1; c <= tc; c++) {
        vector<string> shuffled, unshuffled;
        shuffled.resize(25);
        unshuffled.resize(27);
        for (int i = 24; i >= 0; i--)
            cin >> shuffled[i];
        for (int i = 26; i >= 0; i--)
            cin >> unshuffled[i];

        int y = 0;
        int count = 3;
        while (count--) {
            string top = shuffled.back();
            shuffled.pop_back();
            int r = top[0];
            int x = r >= '2' && r <= '9' ? r - '0' : 10;
            y += x;
            x = 10 - x;
            while (x-- && shuffled.size() > 0)
                 shuffled.pop_back();
            y += x + 1;
        }

        for (auto it = shuffled.begin(); it != shuffled.end(); it++)
            unshuffled.push_back(*it);

        cout << "Case " << c << ": " << unshuffled[unshuffled.size() - y] << "\n";
    }
}
