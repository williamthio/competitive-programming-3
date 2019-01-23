#include <iostream>
#include <vector>
#include <map>
#include <limits>

using namespace std;

void uva_00556() {
    struct point {
        int x;
        int y;
        point(int x, int y) {
            this->x = x;
            this->y = y;
        }
    };

    int rowSize, colSize;

    auto getLeft = [&](point dir) -> point {
        if (dir.x == 1 && dir.y == 0)
            return point(0, -1);
        else if (dir.x == 0 && dir.y == -1)
            return point(-1, 0);
        else if (dir.x == -1 && dir.y == 0)
            return point(0, 1);
        else
            return point(1, 0);
    };

    auto getRight = [&](point dir) -> point {
        if (dir.x == 1 && dir.y == 0)
            return point(0, 1);
        else if (dir.x == 0 && dir.y == 1)
            return point(-1, 0);
        else if (dir.x == -1 && dir.y == 0)
            return point(0, -1);
        else
            return point(1, 0);
    };

    auto boundaryCheck = [&](int x, int y) -> bool {
        return !(y < 0 || y >= rowSize || x < 0 || x >= colSize);
    };
    
    while (cin >> rowSize,
        cin >> colSize,
        rowSize && colSize) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<vector<int>> grid;
        grid.resize(rowSize);
        for (int i = 0; i < rowSize; i++) {
            for (int j = 0; j < colSize; j++) {
                char c;
                cin >> c;
                grid[i].push_back((c - '0') * -1);
            }
        }

        point curr(0, rowSize - 1);
        point dir(1, 0);
        do {
            point right = getRight(dir);
            if (boundaryCheck(curr.x + right.x, curr.y + right.y)
                && grid[curr.y + right.y][curr.x + right.x] != -1) {
                dir = right;
                grid[curr.y][curr.x] += 1;
                curr.x += dir.x;
                curr.y += dir.y;
            }
            else if (!boundaryCheck(curr.x + dir.x, curr.y + dir.y)
                || grid[curr.y + dir.y][curr.x + dir.x] == -1) {
                dir = getLeft(dir);
            }
            else {
                grid[curr.y][curr.x] += 1;
                curr.x += dir.x;
                curr.y += dir.y;
            }
        } while (curr.x != 0 || curr.y != rowSize - 1);

        map<int, int> counter({ {0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0} });
        for (int i = 0; i < rowSize; i++)
            for (int j = 0; j < colSize; j++)
                if (grid[i][j] != -1)
                    counter[grid[i][j]] += 1;

        int max = 5;
        for (auto it = counter.begin(); it != counter.end() && max--; it++)
            printf("%3d", it->second);
        printf("\n");
    }
}
