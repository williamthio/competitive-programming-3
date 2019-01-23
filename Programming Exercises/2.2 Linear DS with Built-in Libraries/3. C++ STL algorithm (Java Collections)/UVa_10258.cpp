#include <iostream>
#include <sstream>
#include <limits>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <functional>
#include <utility>

using namespace std;

void uva_10258() {
    int tc;
    cin >> tc;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int case_itr = 0; case_itr < tc; case_itr++) {
        if (case_itr > 0)
            cout << "\n";

        unordered_set<int> contestants;
        unordered_map<int, int> correctCount, penalty;
        unordered_map<int, unordered_map<int, int>> incorrect;
        unordered_map<int, unordered_map<int, bool>> correct;

        int contestant, problem, time;
        char status;
        string line;
        while (getline(cin, line) && line.size() > 0) {
            stringstream stream(line);
            stream >> contestant;
            stream >> problem;
            stream >> time;
            stream >> status;

            contestants.insert(contestant);

            if (status != 'C' && status != 'I')
                continue;

            if (status == 'I') {
                incorrect[contestant][problem] += 1;
                continue;
            }

            if (correct[contestant][problem])
                continue;

            correct[contestant][problem] = true;
            correctCount[contestant] += 1;
            penalty[contestant] += time + 20 * incorrect[contestant][problem];
        }

        vector<pair<pair<int, int>, int>> scores;
        int n = contestants.size();
        scores.resize(n);
        int i = 0;
        for (auto it = contestants.begin(); it != contestants.end(); it++)
            scores[i++] = make_pair(make_pair(-correctCount[*it], penalty[*it]), *it);
        sort(scores.begin(), scores.end());
        for (i = 0; i < n; i++)
            cout << scores[i].second << " "
                << -scores[i].first.first
                << " " << scores[i].first.second << "\n";
    }
}
