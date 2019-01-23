#include <iostream>
#include <functional>
#include <utility>

using namespace std;

void uva_10503() {
    int n;
    while (cin >> n, n) {
        int m;
        cin >> m;

        pair<int, int> left, right;
        cin >> left.first;
        cin >> left.second;
        cin >> right.first;
        cin >> right.second;

        pair<int, int> pieces[14];
        for (int i = 0; i < m; i++) {
            cin >> pieces[i].first;
            cin >> pieces[i].second;
        }

        function<bool(int, int, int)> check = [&](int end, int chosen, int space) {
            if (space == 0)
                return end == right.first;

            bool solution = false;
            for (int i = 0; i < m; i++) {
                if (chosen & (1 << i))
                    continue;
                pair<int, int> piece = pieces[i];
                if (end == piece.first || end == piece.second) {
                    int newEnd = end == piece.first ? piece.second : piece.first;
                    int newChosen = chosen | (1 << i);
                    solution = solution || check(newEnd, newChosen, space - 1);
                }
            }

            return solution;
        };

        cout << (check(left.second, 0, n) ? "YES\n" : "NO\n");
    }
}
