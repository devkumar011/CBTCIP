#include<iostream>
#include<string>

using namespace std;

void drawBoard(char board[3][3]) {
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

bool checkWin(char board[3][3], char player) {
    // Check rows
    for(int i=0; i<3; i++) {
        if(board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }

    // Check columns
    for(int i=0; i<3; i++) {
        if(board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }

    // Check diagonals
    if(board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if(board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }

    return false;
}

bool checkTie(char board[3][3]) {
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(board[i][j] == '-') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    char board[3][3] = {{'-','-','-'},
                        {'-','-','-'},
                        {'-','-','-'}};

    char player = 'X';
    int row, col;

    while(true) {
        drawBoard(board);
        cout << "Player " << player << ", enter row and column (0-2): ";
        cin >> row >> col;

        if(board[row][col] != '-') {
            cout << "Invalid move, try again.\n";
            continue;
        }

        board[row][col] = player;

        if(checkWin(board, player)) {
            drawBoard(board);
            cout << "Player " << player << " wins!\n";
            break;
        }

        if(checkTie(board)) {
            drawBoard(board);
            cout << "It's a tie!\n";
            break;
        }

        player = (player == 'X') ? 'O' : 'X';
    }

    return 0;
}
