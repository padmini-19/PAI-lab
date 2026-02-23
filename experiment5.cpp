#include <iostream>
using namespace std;

char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

// Function to print the board
void printBoard() {
    cout << "\n";
    cout << board[0] << " | " << board[1] << " | " << board[2] << "\n";
    cout << "--+---+--\n";
    cout << board[3] << " | " << board[4] << " | " << board[5] << "\n";
    cout << "--+---+--\n";
    cout << board[6] << " | " << board[7] << " | " << board[8] << "\n";
    cout << "\n";
}

// Function to check winner
int checkWinner() {

    // Winning combinations
    int winPatterns[8][3] = {
        {0,1,2},{3,4,5},{6,7,8}, // rows
        {0,3,6},{1,4,7},{2,5,8}, // columns
        {0,4,8},{2,4,6} // diagonals
    };

    for(int i = 0; i < 8; i++) {
        if(board[winPatterns[i][0]] == board[winPatterns[i][1]] &&
           board[winPatterns[i][1]] == board[winPatterns[i][2]] &&
           board[winPatterns[i][0]] != ' ')
        {
            if(board[winPatterns[i][0]] == 'O')
                return +1; // AI wins
            else
                return -1; // Human wins
        }
    }

    return 0; // No winner yet
}

// Check if board is full
bool isFull() {
    for(int i = 0; i < 9; i++) {
        if(board[i] == ' ')
            return false;
    }
    return true;
}

// Minimax function
int minimax(bool isAI) {

    int score = checkWinner();

    // If game ended, return score
    if(score == 1 || score == -1)
        return score;

    if(isFull())
        return 0; // Draw

    if(isAI) {
        int best = -1000;

        for(int i = 0; i < 9; i++) {
            if(board[i] == ' ') {
                board[i] = 'O';
                best = max(best, minimax(false));
                board[i] = ' ';
            }
        }
        return best;
    }
    else {
        int best = 1000;

        for(int i = 0; i < 9; i++) {
            if(board[i] == ' ') {
                board[i] = 'X';
                best = min(best, minimax(true));
                board[i] = ' ';
            }
        }
        return best;
    }
}

// Function to find best move for AI
void bestMove() {

    int bestVal = -1000;
    int move = -1;

    for(int i = 0; i < 9; i++) {
        if(board[i] == ' ') {
            board[i] = 'O';
            int moveVal = minimax(false);
            board[i] = ' ';

            if(moveVal > bestVal) {
                move = i;
                bestVal = moveVal;
            }
        }
    }

    board[move] = 'O';
}

// Main function
int main() {

    cout << "TIC TAC TOE\n";
    cout << "You are X, AI is O\n";

    while(true) {

        printBoard();

        // Human move
        int pos;
        cout << "Enter position (1-9): ";
        cin >> pos;
        pos--; // Convert to 0 index

        if(board[pos] != ' ') {
            cout << "Invalid move! Try again.\n";
            continue;
        }

        board[pos] = 'X';

        if(checkWinner() == -1) {
            printBoard();
            cout << "You win!\n";
            break;
        }

        if(isFull()) {
            printBoard();
            cout << "Draw!\n";
            break;
        }

        // AI move
        bestMove();

        if(checkWinner() == 1) {
            printBoard();
            cout << "AI wins!\n";
            break;
        }

        if(isFull()) {
            printBoard();
            cout << "Draw!\n";
            break;
        }
    }

    return 0;
}
