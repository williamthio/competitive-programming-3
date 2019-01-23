#include <iostream>
#include <ctime>
#include <vector>
#include <limits>
#include <string>

using namespace std;

void uva_11956() {
    int tc, i, j, pointer, v;
    vector<int> arr;
    string s;
    cin >> tc;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (i = 1; i <= tc; i++) {
        arr.clear();
        arr.resize(100);
        pointer = 0;
        getline(cin, s);
        for (char c : s) {
            switch (c) {
            case '<':
                v = pointer - 1;
                pointer = v < 0 ? 99 : v;
                break;
            case '>':
                v = pointer + 1;
                pointer = v > 99 ? 0 : v;
                break;
            case '+':
                v = arr[pointer] + 1;
                arr[pointer] = v > 255 ? 0 : v;
                break;
            case '-':
                v = arr[pointer] - 1;
                arr[pointer] = v < 0 ? 255 : v;
                break;
            }
        }
        printf("Case %d: ", i);
        for (j = 0; j < 100; j++) {
            if (j > 0)
                printf(" ");
            printf("%02X", arr[j]);
        }
        printf("\n");
    }
}
