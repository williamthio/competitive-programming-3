#include <iostream>
#include <map>
#include <string>
#include <iomanip>

using namespace std;

void uva_10226() {
    int tc;
    cin >> tc;
    cin.get();
    cin.get();
    for (int i = 0; i < tc; i++) {
        string tree;
        int count = 0;
        map<string, int> trees;
        while (getline(cin, tree) && !tree.empty()) {
            trees[tree]++;
            count++;
        }

        if (i > 0)
            cout << "\n";
        for (auto it = trees.begin(); it != trees.end(); it++) {
            cout << it->first << " "
                << fixed << setprecision(4)
                << ((double)it->second / count * 100)
                << "\n";
        }
    }
}
