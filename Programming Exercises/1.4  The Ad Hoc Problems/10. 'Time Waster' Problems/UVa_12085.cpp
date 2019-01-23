#include <iostream>
#include <limits>
#include <string>
#include <functional>

using namespace std;

void uva_12085() {
    auto isValid = [&](string number) -> bool {
        int n = number.size();
        if (n == 0 || number[0] != '0' || n > 1 && number[1] == '0')
            return false;
        long num = stol(number);
        if (num < 100 || num > 2000000000)
            return false;
        return true;
    };

    auto printNumberRange = [&](int min, int max) {
        if (min == max) {
            cout << "0" << min << "\n";
        }
        else {
            string left = to_string(min);
            string right = to_string(max);
            int start = 0;
            while (left[start] == right[start])
                start++;
            string trimmedRight = "";
            for (int i = start, n = right.size(); i < n; i++)
                trimmedRight += right[i];
            cout << "0" << left << "-" << trimmedRight << "\n";
        }
    };

    int n, tc = 0;
    while (cin >> n, n) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Case " << ++tc << ":\n";

        long min = 0, max = 0;

        string number;
        for (int i = 0; i < n; i++) {
            getline(cin, number);

            if (!isValid(number))
                continue;

            if (min == 0) {
                min = max = stol(number);
                continue;
            }

            int curr = stol(number);
            if (curr - max == 1) {
                max = curr;
                continue;
            }

            printNumberRange(min, max);
            min = max = curr;
        }
        printNumberRange(min, max);
        cout << "\n";
    }
}
