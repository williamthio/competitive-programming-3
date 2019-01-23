#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <functional>

using namespace std;

void uva_00732() {
    string word, anagram;
    while (getline(cin, word)) {
        while (word.size() == 0)
            getline(cin, word);
        getline(cin, anagram);
        while (anagram.size() == 0)
            getline(cin, anagram);

        vector<string> output;
        int n = word.size();

        function<void(stack<char>, string, int, int)> parse =
            [&](stack<char> s, string seq, int wp, int ap) {
            if (ap == n) {
                output.push_back(seq);
                return;
            }
            if (wp == n && (s.empty() || s.top() != anagram[ap]))
                return;

            while ((s.empty() || s.top() != anagram[ap]) && wp < n) {
                s.push(word[wp++]);
                seq += 'i';
            }

            while (!s.empty() && s.top() == anagram[ap]) {
                if (wp < n) {
                    stack<char> newStack = s;
                    newStack.push(word[wp]);
                    parse(newStack, seq + 'i', wp + 1, ap);
                }

                s.pop();
                seq += 'o';
                ap++;
            }

            parse(s, seq, wp, ap);
        };

        if (n == anagram.size()) {
            stack<char> s;
            parse(s, "", 0, 0);
        }

        cout << "[\n";
        for (int i = 0, n = output.size(); i < n; i++) {
            for (int j = 0, sn = output[i].size(); j < sn; j++) {
                if (j > 0)
                    cout << " ";
                cout << output[i][j];
            }
            cout << "\n";
        }
        cout << "]\n";
    }
}
