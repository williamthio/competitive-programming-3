#include <iostream>
#include <limits>
#include <string>
#include <unordered_map>

using namespace std;

void uva_00489() {
    int round;
    while (cin >> round, round != -1) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string answer, guess;
        getline(cin, answer);
        getline(cin, guess);

        unordered_map<char, bool> characters;
        unordered_map<char, bool> guesses;

        int n = answer.size();
        for (int i = 0; i < n; i++)
            characters[answer[i]] = true;

        int available = characters.size();
        int correct = 0;
        int wrong = 0;
        n = guess.size();
        for (int i = 0; i < n && correct < available && wrong < 7; i++) {
            if (characters[guess[i]]) {
                characters[guess[i]] = false;
                correct++;
            }
            else if (!guesses[guess[i]]) {
                wrong++;
            }
            guesses[guess[i]] = true;
        }

        cout << "Round " << round << "\n";
        if (correct == available)
            cout << "You win.\n";
        else if (wrong == 7)
            cout << "You lose.\n";
        else
            cout << "You chickened out.\n";
    }
}
