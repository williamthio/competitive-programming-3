#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

void uva_00735() {
    const int kScores[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
        12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 24, 26, 27, 28,
        30, 32, 33, 34, 36, 38, 39, 40, 42, 45, 48, 50, 51, 54, 57, 60 };
    const int kSn = 43;

    auto combine = [&](int a, int b) {
        int times = 1;
        while (times <= b)
            times *= 10;
        return a * times + b;
    };

    int score;
    while (cin >> score, score > 0) {
        unordered_map<int, bool> exist;
        int combination = 0;
        int permutation = 0;

        if (score <= 180) {
            for (int i = 0; i < kSn && kScores[i] <= score; i++) {
                int id = kScores[i];

                for (int j = 0; j < kSn && id + kScores[j] <= score; j++) {
                    int jd = id + kScores[j];

                    for (int k = 0; k < kSn && jd + kScores[k] <= score; k++) {
                        int kd = jd + kScores[k];

                        if (kd == score) {
                            permutation++;

                            int a = id;
                            int b = jd - id;
                            int c = kd - jd;

                            if (a > c)
                                swap(a, c);
                            if (a > b)
                                swap(a, b);
                            if (b > c)
                                swap(b, c);

                            int ordered = combine(a, combine(b, c));

                            if (!exist[ordered]) {
                                exist[ordered] = true;
                                combination++;
                            }
                        }
                    }
                }
            }
        }

        if (permutation == 0)
            cout << "THE SCORE OF " << score << " CANNOT BE MADE WITH THREE DARTS.\n";
        else {
            cout << "NUMBER OF COMBINATIONS THAT SCORES " << score << " IS " << combination << ".\n"
                << "NUMBER OF PERMUTATIONS THAT SCORES " << score << " IS " << permutation << ".\n";
        }
        cout << "**********************************************************************\n";
    }
    cout << "END OF OUTPUT\n";
}
