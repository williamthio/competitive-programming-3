#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

void uva_00462() {
    string hand[13];
    while (cin >> hand[0], !cin.fail()) {
        for (int i = 1; i < 13; i++)
            cin >> hand[i];
        int points = 0;
        unordered_map<char, int> suitCount;
        for (int i = 0; i < 13; i++) {
            char rank = hand[i][0];
            if (rank == 'A')
                points += 4;
            else if (rank == 'K')
                points += 3;
            else if (rank == 'Q')
                points += 2;
            else if (rank == 'J')
                points += 1;
            suitCount[hand[i][1]] += 1;
        }
        unordered_map<char, bool> suitStopped;
        suitStopped['S'] = suitStopped['H'] =
            suitStopped['D'] = suitStopped['C'] = false;
        for (int i = 0; i < 13; i++) {
            char rank = hand[i][0];
            char suit = hand[i][1];
            if (rank == 'A') {
                suitStopped[suit] = true;
            } else if (rank == 'K') {
                if (suitCount[suit] == 1)
                    points--;
                if (suitCount[suit] > 1)
                    suitStopped[suit] = true;
            }
            else if (rank == 'Q') {
                if (suitCount[suit] <= 2)
                    points--;
                if (suitCount[suit] > 2)
                    suitStopped[suit] = true;
            }
            else if (rank == 'J') {
                if (suitCount[suit] <= 3)
                    points--;
            }
        }
        int additionalPoints = 0;
        char suits[] = { 'S', 'H', 'D', 'C' };
        for (int i = 0; i < 4; i++) {
            if (suitCount[suits[i]] == 2)
                additionalPoints += 1;
            else if (suitCount[suits[i]] < 2)
                additionalPoints += 2;
        }
        if (points + additionalPoints < 14) {
            cout << "PASS\n";
            continue;
        }
        if (points >= 16) {
            bool allStopped = true;
            for (int i = 0; i < 4; i++)
                if (!suitStopped[suits[i]]) {
                    allStopped = false;
                    break;
                }
            if (allStopped) {
                cout << "BID NO-TRUMP\n";
                continue;
            }
        }
        char suit = 'S';
        int max = suitCount['S'];
        for (int i = 1; i < 4; i++)
            if (max < suitCount[suits[i]]) {
                suit = suits[i];
                max = suitCount[suit];
            }
        cout << "BID " << suit << "\n";
    }
}
