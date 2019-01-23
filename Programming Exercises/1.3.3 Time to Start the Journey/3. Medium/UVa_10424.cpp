#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int get_sum(string s) {
    int n = s.size();
    int total = 0;
    char c;
    while (n--) {
        c = s[n];
        if (isalpha(c))
            total += c - (isupper(c) ? 'A' : 'a') + 1;
    }
    s = to_string(total);
    n = s.size();
    while (n > 1) {
        total = 0;
        while (n--)
            total += s[n] - '0';
        s = to_string(total);
        n = s.size();
    }
    return total;
}

void uva_10424() {
    string s;
    int r1, r2;
    while (getline(cin, s)) {
        r1 = get_sum(s);
        getline(cin, s);
        r2 = get_sum(s);
        printf("%.2f %%\n", (r1 < r2 ? (double)r1 / r2 : (double)r2 / r1) * 100);
    }
}
