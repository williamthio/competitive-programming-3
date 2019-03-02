#include <iostream>

using namespace std;

void uva_11831() {
    int dx[] = { -1,  0, 1, 0 };
    int dy[] = {  0, -1, 0, 1 };
    int n, m, s;
    while (cin >> n, cin >> m, cin >> s, n || m || s) {
        char grid[100][100];
        int x, y, dir;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
                if (grid[i][j] < 'A')
                    continue;
                x = j;
                y = i;
                switch (grid[i][j]) {
                    case 'O': dir = 0;
                              break;
                    case 'N': dir = 1;
                              break;
                    case 'L': dir = 2;
                              break;
                    case 'S': dir = 3;
                              break;
                }
            }
        }

        int count = 0;
        while (s--) {
            char ins;
            cin >> ins;
            if (ins == 'D')
                dir = (dir + 1) % 4;
            else if (ins == 'E')
                dir = (dir + 3) % 4;
            else {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if (0 <= nx && nx < m && 0 <= ny &&  ny < n && grid[ny][nx] != '#') {
                    x = nx;
                    y = ny;
                    if (grid[y][x] == '*') {
                        count++;
                        grid[y][x] = '.';
                    }
                }
            }
        }

        cout << count << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    uva_11831();
    return 0;
}

