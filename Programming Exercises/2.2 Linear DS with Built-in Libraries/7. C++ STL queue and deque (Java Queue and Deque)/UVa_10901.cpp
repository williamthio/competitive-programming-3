#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

void uva_10901() {
    struct car {
        int index;
        int arriveTime;
        bool fromLeft;
    };

    int tc;
    cin >> tc;
    for (int ci = 0; ci < tc; ci++) {
        if (ci > 0)
            cout << "\n";

        unsigned int n, t, m;
        cin >> n;
        cin >> t;
        cin >> m;

        unordered_map<bool, queue<car>> banks;
        for (unsigned int i = 0; i < m; i++) {
            car c;
            c.index = i;
            cin >> c.arriveTime;
            string comeFrom;
            cin >> comeFrom;
            c.fromLeft = comeFrom.compare("left") == 0;
            banks[c.fromLeft].push(c);
        }

        vector<int> carArrivals;
        for (unsigned int i = 0; i < m; i++)
            carArrivals.push_back(-1);

        bool atLeft = true;
        int minutesPassed = 0;
        while (!banks[true].empty() || !banks[false].empty()) {
            vector<car> cars;

            while (!banks[atLeft].empty()
                && banks[atLeft].front().arriveTime <= minutesPassed
                && cars.size() < n) {
                cars.push_back(banks[atLeft].front());
                banks[atLeft].pop();
            }

            if (cars.empty()) {
                if (banks[true].empty()) {
                    cars.push_back(banks[false].front());
                    banks[false].pop();
                }
                else if (banks[false].empty()) {
                    cars.push_back(banks[true].front());
                    banks[true].pop();
                }
                else {
                    int leftTime = banks[true].front().arriveTime;
                    int rightTime = banks[false].front().arriveTime;
                    bool isLeft;
                    if (leftTime < rightTime)
                        isLeft = true;
                    else if (leftTime > rightTime)
                        isLeft = false;
                    else
                        isLeft = atLeft;

                    cars.push_back(banks[isLeft].front());
                    banks[isLeft].pop();
                }
            }

            if (carArrivals[cars[0].index] != -1)
                continue;

            if (minutesPassed < cars[0].arriveTime)
                minutesPassed = cars[0].arriveTime;

            if (cars[0].fromLeft != atLeft) {
                minutesPassed += t;
                atLeft = cars[0].fromLeft;
            }

            while (!banks[atLeft].empty()
                && banks[atLeft].front().arriveTime <= minutesPassed
                && cars.size() < n) {
                cars.push_back(banks[atLeft].front());
                banks[atLeft].pop();
            }

            minutesPassed += t;
            atLeft = !atLeft;

            for (int i = 0, n = cars.size(); i < n; i++)
                carArrivals[cars[i].index] = minutesPassed;
        }

        for (unsigned int i = 0; i < m; i++)
            cout << carArrivals[i] << "\n";
    }
}
