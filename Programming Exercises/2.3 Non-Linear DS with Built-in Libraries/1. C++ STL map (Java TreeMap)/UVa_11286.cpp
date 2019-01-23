#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void uva_11286() {
    int n;
    while (cin >> n, n) {
        int max = 0;
        int maxCount = 0;
        unordered_map<string, int> combinationCount;
        for (int i = 0; i < n; i++) {
            vector<string> courses(5);
            for (int j = 0; j < 5; j++)
                cin >> courses[j];
            sort(courses.begin(), courses.end());
            string combination = "";
            for (string s : courses)
                combination += s;
            combinationCount[combination] += 1;
        }
        for (auto cc : combinationCount) {
            if (max < cc.second) {
                max = cc.second;
                maxCount = 0;
            }
            if (max == cc.second) {
                maxCount += max;
            }
        }
        cout << maxCount << "\n";
    }
}
