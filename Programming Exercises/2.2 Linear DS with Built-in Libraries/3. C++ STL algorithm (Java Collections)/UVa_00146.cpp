#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void uva_00146() {
    string code;
    while (getline(cin, code), code.compare("#") != 0) {
        if (!next_permutation(code.begin(), code.end()))
            cout << "No Successor\n";
        else
            cout << code << "\n";
    }
}
