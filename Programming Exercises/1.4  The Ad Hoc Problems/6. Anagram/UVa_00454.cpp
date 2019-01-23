#include <iostream>
#include <limits>
#include <string>
#include <cctype>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

void uva_00454() {
    int tc;
    cin >> tc;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    bool start = true;
    while (tc--) {
        if (!start)
            cout << "\n";
        start = false;

        unordered_map<string, vector<string>> anagrams;

        string phrase;
        while (getline(cin, phrase), phrase.size() != 0) {
            string clean = "";
            for (char c : phrase) {
                if (c != ' ')
                    clean += c;
            }
            sort(clean.begin(), clean.end());
            anagrams[clean].push_back(phrase);
        }

        vector<string> output;
        for (auto it = anagrams.begin(); it != anagrams.end(); it++) {
            int n = it->second.size();
            if (n < 2)
                continue;

            vector<string> arr = it->second;
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (arr[i] < arr[j])
                        output.push_back(arr[i] + " = " + arr[j]);
                    else
                        output.push_back(arr[j] + " = " + arr[i]);
                }
            }
        }

        sort(output.begin(), output.end());

        for (string s : output)
            cout << s << "\n";
    }
}
