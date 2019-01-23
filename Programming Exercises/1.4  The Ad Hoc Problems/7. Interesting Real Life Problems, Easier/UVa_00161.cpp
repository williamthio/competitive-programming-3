#include <iostream>
#include <vector>

using namespace std;

void uva_00161() {
    vector<int> cycles;

    int zeroCount = 0;
    int min = 91;
    int cycle;
    while (cin >> cycle, true) {
        if (cycle <= 0) {
            zeroCount++;
            if (zeroCount >= 2)
                break;

            bool found = false;
            int secondsPassed = min * 2;
            while (secondsPassed <= 18000) {
                bool allGreen = true;
                for (auto it = cycles.begin(); it != cycles.end(); it++) {
                    int pos = secondsPassed % (*it * 2);
                    if (pos >= *it - 5) {
                        allGreen = false;
                        break;
                    }
                }
                found = found || allGreen;
                if (found)
                    break;

                int pos = secondsPassed % (min * 2);
                if (pos < min - 6)
                    secondsPassed++;
                else
                    secondsPassed += min + 6;
            }

            if (found) {
                printf("%02d:%02d:%02d\n", secondsPassed / 3600,
                    (secondsPassed % 3600) / 60, secondsPassed % 60);
            }
            else {
                printf("Signals fail to synchronise in 5 hours\n");
            }

            min = 91;
            cycles.clear();
        }
        else {
            zeroCount = 0;
            cycles.push_back(cycle);
            if (min > cycle)
                min = cycle;
        }
    }
}
