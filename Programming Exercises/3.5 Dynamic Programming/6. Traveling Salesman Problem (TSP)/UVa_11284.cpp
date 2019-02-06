#include <iostream>
#include <functional>
#include <cstring>
#include <algorithm>
#include <iomanip>

using namespace std;

void uva_11284() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n;
        cin >> m;

        double dist[51][51];
        fill_n(&dist[0][0], 51 * 51, 1 << 30);

        while (m--) {
            int a, b;
            double cost;
            cin >> a;
            cin >> b;
            cin >> cost;
            if (dist[a][b] > cost)
                dist[a][b] = dist[b][a] = cost;
        }

        for (int i = 0; i <= n; i++)
            dist[i][i] = 0;

        for (int k = 0; k <= n; k++) {
            for (int i = 0; i <= n; i++) {
                for (int j = 0; j <= n; j++) {
                    if (dist[i][j] > dist[i][k] + dist[k][j])
                        dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }

        int p;
        cin >> p;

        int stores[12];
        double prices[12];

        for (int i = 0; i < p; i++) {
            cin >> stores[i];
            cin >> prices[i];
        }

        double memo[51][1 << 12];
        fill_n(&memo[0][0], 51 * (1 << 12), -1.0);

        function<double(int, int)> shop = [&](int pos, int visited) -> double {
            if (visited == (1 << p) - 1)
                return -dist[pos][0];
            if (memo[pos][visited] != -1)
                return memo[pos][visited];
            double saved = 1 << 31;
            for (int i = 0; i < p; i++) {
                if (!(visited & (1 << i))) {
                    saved = max(saved, prices[i] - dist[pos][stores[i]] - dist[stores[i]][0]);
                    saved = max(saved, prices[i] - dist[pos][stores[i]] + shop(stores[i], visited | (1 << i)));
                }
            }
            return memo[pos][visited] = saved;
        };

        double saved = shop(0, 0);
        if (saved >= 0.005)
            cout << "Daniel can save $" << fixed << setprecision(2) << saved << "\n";
        else
            cout << "Don't leave the house\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    uva_11284();
    return 0;
}

