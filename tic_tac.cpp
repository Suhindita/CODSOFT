#include <iostream>
#include <vector>
using namespace std;

char board[3][3];
char current;

void reset() {
    char c = '1';
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            board[i][j] = c++;
}

void show() {
    cout << "\n";
    for (int i = 0; i < 3; ++i) {
        cout << " ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        if (i < 2) cout << "\n-----------\n";
    }
    cout << "\n";
}

bool makeMove(int cell) {
    int row = (cell - 1) / 3;
    int col = (cell - 1) % 3;

    if (cell < 1 || cell > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
        return false;
    }

    board[row][col] = current;
    return true;
}

bool checkWin() {
    // Rows & Columns
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == current &&
             board[i][1] == current &&
             board[i][2] == current) ||
            (board[0][i] == current &&
             board[1][i] == current &&
             board[2][i] == current)) {
            return true;
        }
    }

    // Diagonals
    if ((board[0][0] == current &&
         board[1][1] == current &&
         board[2][2] == current) ||
        (board[0][2] == current &&
         board[1][1] == current &&
         board[2][0] == current)) {
        return true;
    }

    return false;
}

bool checkDraw() {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

void change() {
    current = (current == 'X') ? 'O' : 'X';
}

int main() {
    char redo;
    do {
        reset();
        current = 'X';
        bool gameOver = false;

        cout << "Welcome!\n";
        show();

        while (!gameOver) {
            int move;
            cout << "\nPlayer " << current << ", enter your move (1-9): ";
            cin >> move;

            if (!makeMove(move)) {
                cout << "Invalid move, Try again.\n";
                continue;
            }

            show();

            if (checkWin()) {
                cout << "\nPlayer " << current << " wins!\n";
                gameOver = true;
            } else if (checkDraw()) {
                cout << "\nIt's a draw!\n";
                gameOver = true;
            } else {
                change();
            }
        }

        cout << "\nDo you want to play again? (y/n): ";
        cin >> redo;

    } while (redo == 'y' || redo == 'Y');

    cout << "See you soon\n";
    return 0;
}
