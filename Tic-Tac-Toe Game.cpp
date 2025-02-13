#include <iostream>

using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int currentPlayer = 1;
char mark;

void displayBoard() {
    system("clear"); // Use "cls" for Windows
    cout << "Tic-Tac-Toe Game" << endl;
    cout << "Player 1 (X) - Player 2 (O)" << endl;
    cout << endl;
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << " " << board[i][j] << " ";
            if (j < 2) cout << "|";
        }
        cout << endl;
        if (i < 2) cout << "---+---+---" << endl;
    }
    cout << endl;
}

bool checkWin() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;
    return false;
}

bool isDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') return false;
        }
    }
    return true;
}

void makeMove() {
    int choice;
    cout << "Player " << currentPlayer << "'s turn. Enter a number: ";
    cin >> choice;
    
    mark = (currentPlayer == 1) ? 'X' : 'O';
    
    bool validMove = false;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == choice + '0') {
                board[i][j] = mark;
                validMove = true;
                break;
            }
        }
        if (validMove) break;
    }
    
    if (!validMove) {
        cout << "Invalid move! Try again." << endl;
        makeMove();
    }
}

int main() {
    while (true) {
        displayBoard();
        makeMove();
        
        if (checkWin()) {
            displayBoard();
            cout << "Player " << currentPlayer << " wins!" << endl;
            break;
        }
        
        if (isDraw()) {
            displayBoard();
            cout << "It's a draw!" << endl;
            break;
        }
        
        currentPlayer = (currentPlayer == 1) ? 2 : 1;
    }
    return 0;
}
