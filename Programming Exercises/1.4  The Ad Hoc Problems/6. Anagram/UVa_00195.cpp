#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

void uva_00195() {
    int n;
    cin >> n;
    while (n--) {
        string word;
        cin >> word;

        sort(word.begin(), word.end());

        vector<string> permutation;
        do {
            permutation.push_back(word);
        } while (next_permutation(word.begin(), word.end()));

        sort(permutation.begin(), permutation.end(), [&](string s1, string s2) {
            vector<int> a, b;
            for (char c : s1) {
                if (isupper(c))
                    a.push_back(2 * (c - 'A'));
                else
                    a.push_back(1 + 2 * (c - 'a'));
            }
            for (char c : s2) {
                if (isupper(c))
                    b.push_back(2 * (c - 'A'));
                else
                    b.push_back(1 + 2 * (c - 'a'));
            }
            return a < b;
        });

        for (auto it = permutation.begin(); it != permutation.end(); it++) {
            cout << *it << "\n";
        }
    }
}
