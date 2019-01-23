#include <iostream>
#include <list>
#include <string>

using namespace std;

void uva_11988() {
    string line;
    while (getline(cin, line)) {
        list<char> text;
        auto curr = text.begin();
        for (char c : line) {
            if (c == '[')
                curr = text.begin();
            else if (c == ']')
                curr = text.end();
            else
                text.insert(curr, c);
        }
        line = "";
        for (char c : text)
            line += c;
        cout << line << "\n";
    }
}
