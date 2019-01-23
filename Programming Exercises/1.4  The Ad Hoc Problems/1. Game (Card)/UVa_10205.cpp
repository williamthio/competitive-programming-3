#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <limits>

using namespace std;

void uva_10205() {
    string ranks[] = {
        "2", "3", "4", "5",
        "6", "7", "8", "9", "10",
        "Jack", "Queen", "King", "Ace"
    };
    string suits[] = { "Clubs", "Diamonds",
        "Hearts", "Spades" };
    int tc;
    cin >> tc;
    bool start = true;
    while (tc--) {
        if (!start)
            cout << "\n";
        start = false;
        int n;
        cin >> n;
        vector<unordered_map<int, int>> shuffles;
        shuffles.resize(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 52; j++) {
                int v;
                cin >> v;
                shuffles[i][j] = v - 1;
            }
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        vector<int> cards;
        for (int i = 0; i < 52; i++)
            cards.push_back(i);
        string temp;
        while (getline(cin, temp) && temp.size() > 0) {
            int i = stoi(temp) - 1;
            vector<int> newOrder;
            newOrder.resize(52);
            for (int j = 0; j < 52; j++)
                newOrder[j] = cards[shuffles[i][j]];
            cards = newOrder;
        }
        for (int i = 0; i < 52; i++) {
            cout << ranks[cards[i] % 13]
                << " of "
                << suits[cards[i] / 13] << "\n";
        }
    }

}
