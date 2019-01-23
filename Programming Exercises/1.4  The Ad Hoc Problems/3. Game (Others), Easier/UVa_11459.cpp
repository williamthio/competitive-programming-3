#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

void uva_11459() {
    int tc;
    cin >> tc;
    while (tc--) {
        int playerSize, snakeOrLadderSize, dieRollSize;
        cin >> playerSize;
        cin >> snakeOrLadderSize;
        cin >> dieRollSize;

        map<int, int> players;
        for (int i = 0; i < playerSize; i++)
            players[i] = 1;

        unordered_map<int, int> snakes, ladders;
        while (snakeOrLadderSize--) {
            int from, to;
            cin >> from;
            cin >> to;

            if (from < to)
                ladders[from] = to;
            else
                snakes[from] = to;
        }

        int turn = 0;
        bool gameOver = playerSize <= 0;
        while (dieRollSize--) {
            int roll;
            cin >> roll;

            if (gameOver)
                continue;

            int curr = turn % playerSize;
            players[curr] += roll;
            if (players[curr] >= 100) {
                players[curr] = 100;
                gameOver = true;
            }
            else if (snakes[players[curr]] > 0) {
                players[curr] = snakes[players[curr]];
            }
            else if (ladders[players[curr]] > 0) {
                players[curr] = ladders[players[curr]];
                if (players[curr] >= 100) {
                    players[curr] = 100;
                    gameOver = true;
                }
            }

            turn += 1;
        }

        for (auto it = players.begin(); it != players.end(); it++) {
            cout << "Position of player " << it->first + 1
                << " is " << it->second << ".\n";
        }
    }
}
