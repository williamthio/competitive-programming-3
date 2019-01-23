#include <iostream>
#include <string>

using namespace std;

void uva_00584() {
    string s;
    while (getline(cin, s), s.compare("Game Over") != 0) {
        int game[11][2] = { 0 };
        int frame = 0, roll = 0;
        for (int i = 0, n = s.size(); i < n && frame < 11 && roll < 2; i++) {
            char c = s[i];
            if (c != ' ') {
                if (c == 'X') {
                    game[frame][roll] = 10;
                    if (frame < 10) {
                        frame++;
                        roll = 0;
                    }
                    else {
                        roll++;
                    }
                }
                else {
                    if (c == '/')
                        game[frame][roll] = 10 - game[frame][0];
                    else
                        game[frame][roll] = c - '0';

                    if (++roll > 1) {
                        frame++;
                        roll = 0;
                    }
                }
            }
        }

        int score = 0;
        for (int i = 0; i < 10; i++) {
            if (game[i][0] == 10) {
                score += 10 + game[i + 1][0] + game[i + 1][1];
                if (game[i + 1][0] == 10 && i < 9) {
                    score += game[i + 2][0];
                }
            }
            else if (game[i][0] + game[i][1] == 10) {
                score += 10 + game[i + 1][0];
            }
            else {
                score += game[i][0] + game[i][1];
            }
        }

        cout << score << "\n";
    }
}
