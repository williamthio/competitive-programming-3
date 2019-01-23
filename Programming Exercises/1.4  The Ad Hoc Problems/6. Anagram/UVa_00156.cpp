#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

void uva_00156() {
    unordered_map<string, string> lastWord;
    unordered_map<string, int> count;

    string word;
    while (cin >> word, word.compare("#") != 0) {
        string sorted = "";
        for (int i = 0, n = word.size(); i < n; i++)
            sorted += tolower(word[i]);
        sort(sorted.begin(), sorted.end());

        lastWord[sorted] = word;
        count[sorted] += 1;
    }

    vector<string> ananagrams;
    for (auto it = count.begin(); it != count.end(); it++) {
        if (it->second == 1) {
            ananagrams.push_back(lastWord[it->first]);
        }
    }

    sort(ananagrams.begin(), ananagrams.end());
    for (auto it = ananagrams.begin(); it != ananagrams.end(); it++) {
        cout << *it << "\n";
    }
}
