#include <iostream>
using namespace std;

bool winning(char grid[3][3]) {

    // Rows
    for (int i = 0; i < 3; i++) {
        if (grid[i][0] != ' ' && grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2]) {
            return true;
        }
    }

    // Columns
    for (int i = 0; i < 3; i++) {
        if (grid[0][i] != ' ' && grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i]) {
            return true;
        }
    }

    // Main diagonal
    if (grid[0][0] != ' ' && grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]) {
        return true;
    }

    // Secondary diagonal
    if (grid[0][2] != ' ' && grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0]) {
        return true;
    }

    return false;
}

void printBoard(char grid[3][3]) {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << grid[i][j];
            if (j < 2) {
                cout << " | ";
            }
        }
        cout << "\n";
        if (i < 2) {
            cout << "---------\n";
        }
    }
    cout << "\n";
}

void tic_tac_toe() {

    char grid[3][3] = {
        {' ',' ',' '},
        {' ',' ',' '},
        {' ',' ',' '}
    };

    cout << "Player 1 : X\n";
    cout << "Player 2 : O\n";

    int moves = 0;
    int player = 1;

    while (moves < 9) {

        printBoard(grid);

        int row, col;

        cout << "Player " << player
             << " Enter row (0-2): ";
        cin >> row;

        cout << "Player " << player
             << " Enter column (0-2): ";
        cin >> col;

        if (row < 0 || row > 2 || col < 0 || col > 2) {
            cout << "Invalid position!\n";
            continue;
        }

        if (grid[row][col] != ' ') {
            cout << "Position already occupied!\n";
            continue;
        }

        if (player == 1) {
            grid[row][col] = 'X';
        } else if (player == 2) {
            grid[row][col] = 'O';
        }

        moves++;

        if (winning(grid)) {
            printBoard(grid);
            cout << "Player " << player << " WINS!\n";
            return;
        }

        if ( player == 1 ) {
            player = 2 ;
        } else if ( player == 2) {
            player = 1 ;
        }
    }

    printBoard(grid);
    cout << "The game ends in a DRAW.\n";
}

int main() {

    tic_tac_toe();

    return 0;
}