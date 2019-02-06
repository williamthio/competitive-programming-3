#include <iostream>
#include <functional>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

void uva_00216() {
    int n, tc = 1;
    while (cin >> n, n) {
        int computers[8][2];
        for (int i = 0; i < n; i++) {
            cin >> computers[i][0];
            cin >> computers[i][1];
        }

        function<double(int, int)> distance = [&](int from, int to) {
            return sqrt(pow(computers[to][0] - computers[from][0], 2) +
                    pow(computers[to][1] - computers[from][1], 2));
        };

        double memo[8][1 << 8];
        fill_n(&memo[0][0], 8 * (1 << 8), -1.0);

        function<double(int, int)> connect = [&](int idx, int visited) -> double {
            if (visited == (1 << n) - 1)
                return 0;

            if (idx > -1 && memo[idx][visited] != -1)
                return memo[idx][visited];

            double minDistance = 99999999;
            for (int i = 0; i < n; i++) {
                if (!(visited & (1 << i))) {
                    minDistance = min(minDistance,
                        (idx == -1 ? 0 : distance(idx, i)) + connect(i, visited | (1 << i)));
                }
            }

            return memo[idx][visited] = minDistance;
        };

        function<void(int, int)> printSolution = [&](int idx, int visited) {
            if (visited == (1 << n) - 1)
                return;

            for (int i = 0; i < n; i++) {
                double d = distance(idx, i);
                if (!(visited & (1 << i)) &&
                        (idx > -1 ? d : 0) + connect(i, visited | (1 << i)) == memo[idx][visited]) {
                    if (idx > -1) {
                        printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2f feet.\n",
                                computers[idx][0],
                                computers[idx][1],
                                computers[i][0],
                                computers[i][1],
                                d + 16);
                    }
                    printSolution(i, visited | (1 << i));
                    break;
                }
            }
        };

        printf("**********************************************************\nNetwork #%d\n", tc++);
        double length = connect(-1, 0) + (16 * (n - 1));
        printSolution(-1, 0);
        printf("Number of feet of cable required is %.2f.\n", length);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    uva_00216();
    return 0;
}

