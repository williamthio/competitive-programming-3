#include <iostream>
#include <stack>
#include <limits>
#include <functional>

using namespace std;

void uva_00514() {
    int n;
    int tc = 0;
    while (cin >> n, n) {
        bool possible = true;
        int start;
        while (cin >> start, start) {
            int nextTrainCoach = 1;
            stack<int> station;

            auto moveCoaches = [&](int coachNeeded) -> bool {
                while (nextTrainCoach < coachNeeded)
                    station.push(nextTrainCoach++);

                if (nextTrainCoach == coachNeeded)
                    nextTrainCoach++;
                else if (!station.empty() && station.top() == coachNeeded)
                    station.pop();
                else {
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    return false;
                }

                return true;
            };

            possible = moveCoaches(start);

            for (int i = 1; possible && i < n; i++) {
                int coachNeeded;
                cin >> coachNeeded;
                possible = moveCoaches(coachNeeded);
            }

            cout << (possible ? "Yes" : "No") << "\n";
        }
        cout << "\n";
    }
}
