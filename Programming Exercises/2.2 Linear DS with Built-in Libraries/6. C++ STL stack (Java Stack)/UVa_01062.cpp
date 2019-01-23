#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

void uva_01062() {
    int tc = 0;
    string line;
    while (getline(cin, line) && line.compare("end") != 0) {
        if (line.size() == 0)
            continue;

        vector<stack<char>> stacks;
        for (char c : line) {
            int smallest = 26;
            int smallestIndex = -1;
            for (int i = 0, n = stacks.size(); i < n; i++) {
                char top = stacks[i].top();
                if (top >= c && top - c < smallest) {
                    smallest = top - c;
                    smallestIndex = i;
                }
                if (smallest == 0)
                    break;
            }

            if (smallestIndex == -1) {
                stack<char> s;
                s.push(c);
                stacks.push_back(s);
            }
            else {
                stacks[smallestIndex].push(c);
            }
        }

        cout << "Case " << ++tc << ": " << stacks.size() << "\n";
    }
}
