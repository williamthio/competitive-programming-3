#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <functional>

using namespace std;

void uva_10284() {
    // [0] -> Column, [1] -> Row
    const vector<vector<int>> kKingQueenMoves = {
        {-1, -1}, {0, -1}, {1, -1},
        {-1,  0},          {1,  0},
        {-1,  1}, {0,  1}, {1,  1}
    };
    const vector<vector<int>> kRookMoves = {
                  {0, -1},
        {-1,  0},          {1,  0},
                  {0,  1}
    };
    const vector<vector<int>> kBishopMoves = {
        {-1, -1}, {1, -1},
        {-1,  1}, {1,  1}
    };
    const vector<vector<int>> kKnightMoves = {
                  {-1, -2}, {1, -2},
        {-2, -1},                    {2, -1},
        {-2,  1},                    {2,  1},
                  {-1,  2}, {1,  2}
    };
    const vector<vector<int>> kWhitePawnMoves = { {-1, -1}, {1, -1} };
    const vector<vector<int>> kBlackPawnMoves = { {-1,  1}, {1,  1} };

    const char kEmpty = 'O';
    const char kAttacked = 'X';

    char board[8][8];

    auto boundaryCheck = [&](int row, int col) -> bool {
        return row >= 0 && row < 8 && col >= 0 && col < 8;
    };

    auto singleAttack = [&](vector<vector<int>> moves, int row, int col) {
        int n = moves.size();
        while (n--) {
            vector<int> move = moves[n];
            if (!boundaryCheck(row + move[1], col + move[0]))
                continue;
            if (board[row + move[1]][col + move[0]] == kEmpty)
                board[row + move[1]][col + move[0]] = kAttacked;
        }
    };

    auto continuousAttack = [&](vector<vector<int>> moves, int row, int col) {
        int n = moves.size();
        while (n--) {
            vector<int> move = moves[n];
            int drow = row + move[1];
            int dcol = col + move[0];
            while (boundaryCheck(drow, dcol) &&
                (board[drow][dcol] == kEmpty || board[drow][dcol] == kAttacked)) {
                board[drow][dcol] = kAttacked;
                drow += move[1];
                dcol += move[0];
            }
        }
    };

    string fen;
    while (getline(cin, fen)) {
        int row, col;

        // Clear board
        for (row = 0; row < 8; row++)
            for (col = 0; col < 8; col++)
                board[row][col] = kEmpty;

        // Put chess pieces on board
        row = 0;
        col = 0;
        int n = fen.size();
        for (int i = 0; i < n; i++) {
            char c = fen[i];
            if (isdigit(c))
                col += c - '0';
            else if (c == '/')
                row++, col = 0;
            else
                board[row][col++] = c;
        }

        // Fill attacked cells
        for (row = 0; row < 8; row++) {
            for (col = 0; col < 8; col++) {
                switch (board[row][col])
                {
                case 'k':
                case 'K':
                    singleAttack(kKingQueenMoves, row, col);
                    break;
                case 'q':
                case 'Q':
                    continuousAttack(kKingQueenMoves, row, col);
                    break;
                case 'r':
                case 'R':
                    continuousAttack(kRookMoves, row, col);
                    break;
                case 'b':
                case 'B':
                    continuousAttack(kBishopMoves, row, col);
                    break;
                case 'n':
                case 'N':
                    singleAttack(kKnightMoves, row, col);
                    break;
                case 'p':
                    singleAttack(kBlackPawnMoves, row, col);
                    break;
                case 'P':
                    singleAttack(kWhitePawnMoves, row, col);
                    break;
                }
            }
        }

        // Scan empty cells
        int count = 0;
        for (row = 0; row < 8; row++) {
            for (col = 0; col < 8; col++) {
                if (board[row][col] == kEmpty)
                    count++;
            }
        }
        cout << count << "\n";
    }
}
