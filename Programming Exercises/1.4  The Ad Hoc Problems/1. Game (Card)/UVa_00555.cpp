#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

void uva_00555() {
    unordered_map<char, int> playerKeys = { {'S', 0}, {'W', 1}, {'N', 2}, {'E', 3} };
    unordered_map<char, int> suitKeys = { {'C', 0}, {'D', 1}, {'S', 2}, {'H', 3} };
    unordered_map<char, int> rankKeys = {
        {'2', 0}, {'3', 1}, {'4', 2}, {'5', 3},
        {'6', 4}, {'7', 5}, {'8', 6}, {'9', 7},
        {'T', 8}, {'J', 9}, {'Q', 10}, {'K', 11}, {'A', 12}
    };
    unordered_map<int, char> keyPlayers;
    for (auto it = playerKeys.begin(); it != playerKeys.end(); it++)
        keyPlayers[it->second] = it->first;
    unordered_map<int, char> keySuits;
    for (auto it = suitKeys.begin(); it != suitKeys.end(); it++)
        keySuits[it->second] = it->first;
    unordered_map<int, char> keyRanks;
    for (auto it = rankKeys.begin(); it != rankKeys.end(); it++)
        keyRanks[it->second] = it->first;

    string line;
    while (getline(cin, line), line[0] != '#') {
        vector<vector<vector<int>>> players;
        players.resize(4);
        auto give = [&](int player, string card) {
            players[player].resize(4);
            players[player][suitKeys[card[0]]].push_back(rankKeys[card[1]]);
        };
        char start = line[0];
        int curr = playerKeys[start];
        for (int line_c = 0; line_c < 2; line_c++) {
            getline(cin, line);
            int n = line.size();
            int count = 0;
            string card = "";
            for (int i = 0; i < n; i++) {
                count++;
                card += line[i];
                if (count % 2 == 0) {
                    give(++curr % 4, card);
                    card = "";
                }
            }
        }
        for (int i = 0; i < 4; i++) {
            cout << keyPlayers[i] << ":";
            for (int j = 0; j < 4; j++) {
                vector<int> suit = players[i][j];
                sort(suit.begin(), suit.end());
                int n = suit.size();
                for (int k = 0; k < n; k++) {
                    cout << " " << keySuits[j] << keyRanks[suit[k]];
                }
            }
            cout << "\n";
        }
    }
}
