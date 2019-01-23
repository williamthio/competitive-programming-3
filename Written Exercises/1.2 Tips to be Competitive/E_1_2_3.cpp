#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <math.h>
#include <string>
#include <ctime>
#include <vector>
#include <algorithm>
#include <functional>
#include <bitset>
#include <utility>

using namespace std;

void e_1_2_3() {
    auto no2 = [&]() {
        const double PI = 3.14159265358979323846;
        int num;
        scanf("%d", &num);
        printf("%.*f", num, PI);
    };

    auto no3 = [&]() {
        tm time = { 0, 0, 0, 9, 8 - 1, 2010 - 1900 };
        mktime(&time);
        const char *weekdays[] = { "Sunday", "Monday", "Tuesday",
            "Wednesday", "Thursday", "Friday", "Saturday" };
        printf("%s", weekdays[time.tm_wday]);
    };

    auto no4 = [&]() {
        vector<int> arr;
        for (int i = 0; i < 10; i++)
            arr.push_back(rand() % 10);
        sort(arr.begin(), arr.end());
        arr.erase(unique(arr.begin(), arr.end()), arr.end());
        int n = arr.size();
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
    };

    auto no5 = [&]() {
        // Wrong
        vector<vector<int>> birthdays = {
            { 1, 4, 1996 },
            { 3, 3, 1997 },
            { 2, 2, 1998 }
        };
        auto print = [&]() {
            int n = birthdays.size();
            for (int i = 0; i < n; i++)
                cout << birthdays[i][0] << ", "
                << birthdays[i][1] << ", "
                << birthdays[i][2] << endl;
        };
        sort(birthdays.begin(), birthdays.end(),
            [&](vector<int> i, vector<int> j) { return i[0] < j[0]; });
        print();
        sort(birthdays.begin(), birthdays.end(),
            [&](vector<int> i, vector<int> j) { return i[1] < j[1]; });
        print();
        sort(birthdays.begin(), birthdays.end(),
            [&](vector<int> i, vector<int> j) { return 2018 - i[2] < 2018 - j[2]; });
        print();
    };

    auto no6 = [&]() {
        vector<int> arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        int s = 9;
        if (binary_search(arr.begin(), arr.end(), s)) {
            cout << "Exist";
        }
        else {
            cout << "Not exist";
        }
    };

    auto no7 = [&]() {
        string s = "ABCDEFGHIJ";
        sort(s.begin(), s.end());
        do {
            cout << s << endl;
        } while (next_permutation(s.begin(), s.end()));
    };

    auto no8 = [&]() {
        vector<int> a;
        for (int i = 1; i <= 20; i++)
            a.push_back(i);
        int n = a.size();
        for (int i = 0; i < (1 << n); i++) {
            cout << "{ ";
            for (int j = 0; j < n; j++)
                if (i & (1 << j))
                    cout << a[j] << " ";
            cout << "}" << endl;
        }
    };

    auto no9 = [&]() {
        string s = "FF";
        int x = 16, y = 2;
        int v = stoi(s, 0, x);
        char buffer[110];
        cout << _itoa(v, buffer, y);
    };

    auto no10 = [&]() {
        string s = "line: a70 and z72 will be replaced, aa24 and a872 will not";
        s.replace(s.find("a70"), 3, "***");
        s.replace(s.find("z72"), 3, "***");
        cout << s;
    };
}
