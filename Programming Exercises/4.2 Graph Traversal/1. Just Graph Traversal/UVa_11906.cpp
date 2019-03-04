#include <iostream>
#include <unordered_set>
#include <utility>
#include <cstring>
#include <functional>

using namespace std;

void uva_11906() {
    const int kUnvisited = 0;
    const int kWater = 1;
    const int kVisited = 2;
    struct pair_hash {
        inline size_t operator ()(const pair<int, int> &v) const {
            return v.first * 31 + v.second;
        }
    };
    int tc;
    cin >> tc;
    for (int ci = 1; ci <= tc; ci++) {
        int r, c, m, n, w;
        cin >> r;
        cin >> c;
        cin >> m;
        cin >> n;
        cin >> w;

        unordered_set<pair<int, int>, pair_hash> moves;
        moves.insert(make_pair(m, n));
        moves.insert(make_pair(-m, n));
        moves.insert(make_pair(m, -n));
        moves.insert(make_pair(-m, -n));
        moves.insert(make_pair(n, m));
        moves.insert(make_pair(-n, m));
        moves.insert(make_pair(n, -m));
        moves.insert(make_pair(-n, -m));

        int grid[100][100];
        memset(grid, kUnvisited, sizeof grid);

        while (w--) {
            int x, y;
            cin >> x;
            cin >> y;
            grid[y][x] = kWater;
        }

        int even = 0;
        int odd = 0;

        function<void(int, int)> dfs = [&](int x, int y) {
            grid[y][x] = kVisited;
            int count = 0;
            for (auto it = moves.begin(); it != moves.end(); it++) {
                int nx = x + it->first;
                int ny = y + it->second;
                if (0 <= nx && nx < r && 0 <= ny && ny < c) {
                    if (grid[ny][nx] != kWater) {
                        count++;
                        if (grid[ny][nx] != kVisited)
                            dfs(nx, ny);
                    }
                }
            } 
            if (count & 1)
                odd++;
            else
                even++;
        };

        dfs(0, 0);

        cout << "Case " << ci << ": " << even << " " << odd << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    uva_11906();
    return 0;
}

