#include <iostream>
#include <vector>
#include <map>

using namespace std;

void ioi2009_poi() {
    int n, t, p, i, j;
    vector<vector<int>> scores;
    vector<int> points, result;
    map<int, map<int, bool>> rankings;
    cin >> n;
    cin >> t;
    cin >> p;
    result.resize(n);
    points.resize(t);
    for (i = 0; i < n; i++) {
        vector<int> score;
        score.resize(t);
        for (j = 0; j < t; j++) {
            cin >> score[j];
            if (score[j] == 0)
                points[j] += 1;
        }
        scores.push_back(score);
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < t; j++) {
            result[i] += scores[i][j] ? points[j] : 0;
        }
        rankings[result[i]][i] = true;
    }
    int rank = 0;
    for (auto it1 = rankings.rbegin(); it1 != rankings.rend(); it1++) {
        for (auto it2 = it1->second.begin(); it2 != it1->second.end(); it2++) {
            rank++;
            if (it2->first == p - 1) {
                cout << result[p - 1] << " " << rank;
                return;
            }
        }
    }
}
