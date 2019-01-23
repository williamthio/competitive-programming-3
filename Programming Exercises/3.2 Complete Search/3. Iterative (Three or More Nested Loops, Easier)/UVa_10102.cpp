#include <iostream>
#include <limits>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

void uva_10102() {
    int m;
    while (cin >> m, !cin.fail()) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<pair<int, int>> ones, threes;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                char color;
                cin >> color;
                if (color == '1')
                    ones.push_back(make_pair(i, j));
                else if (color == '3')
                    threes.push_back(make_pair(i, j));
            }
        }

        vector<int> distances;
        for (pair<int, int> o : ones) {
            int min = -1;
            for (pair<int, int> t : threes) {
                int distance = abs(o.first - t.first) + abs(o.second - t.second);
                if (min == -1 || min > distance)
                    min = distance;
            }

            distances.push_back(min);
        }

        int max = -1;
        for (int d : distances) {
            if (max < d)
                max = d;
        }

        cout << max << "\n";
    }
}
