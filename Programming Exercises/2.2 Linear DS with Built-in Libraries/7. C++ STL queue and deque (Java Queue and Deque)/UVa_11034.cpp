#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;

void uva_11034() {
    int tc;
    cin >> tc;
    while (tc--) {
        int l, m;
        cin >> l;
        cin >> m;
        l *= 100;

        unordered_map<bool, queue<int>> banks;
        while (m--) {
            int carLength;
            string from;
            cin >> carLength;
            cin >> from;
            banks[from.compare("left") == 0].push(carLength);
        }

        int crossTime = 0;
        bool atLeft = true;
        while (!banks[true].empty() || !banks[false].empty()) {
            int lengthSum = 0;
            while (!banks[atLeft].empty()) {
                if (lengthSum + banks[atLeft].front() <= l) {
                    lengthSum += banks[atLeft].front();
                    banks[atLeft].pop();
                }
                else {
                    break;
                }
            }
            atLeft = !atLeft;
            crossTime++;
        }

        cout << crossTime << "\n";
    }
}
