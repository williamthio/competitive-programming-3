#include <iostream>
#include <string>

using namespace std;

void uva_00401() {
    auto getReverse = [&](char c) -> char {
        switch (c)
        {
        case 'A': return 'A';
        case 'E': return '3';
        case 'H': return 'H';
        case 'I': return 'I';
        case 'J': return 'L';
        case 'L': return 'J';
        case 'M': return 'M';
        case 'O': return 'O';
        case 'S': return '2';
        case 'T': return 'T';
        case 'U': return 'U';
        case 'V': return 'V';
        case 'W': return 'W';
        case 'X': return 'X';
        case 'Y': return 'Y';
        case 'Z': return '5';
        case '1': return '1';
        case '2': return 'S';
        case '3': return 'E';
        case '5': return 'Z';
        case '8': return '8';
        default: return '*';
        }
    };

    string s;
    while (getline(cin, s)) {
        bool regular = true;
        bool mirrored = true;
        int n = s.size();
        for (int i = 0; i < n / 2 && (regular || mirrored); i++) {
            char left = s[i];
            char right = s[n - i - 1];
            if (left != right) {
                regular = false;
            }
            if (getReverse(left) != right) {
                mirrored = false;
            }
        }

        if (mirrored && n % 2 == 1) {
            mirrored = getReverse(s[n / 2]) == s[n / 2];
        }

        if (regular && mirrored)
            cout << s << " -- is a mirrored palindrome.\n\n";
        else if (regular)
            cout << s << " -- is a regular palindrome.\n\n";
        else if (mirrored)
            cout << s << " -- is a mirrored string.\n\n";
        else
            cout << s << " -- is not a palindrome.\n\n";
    }
}
