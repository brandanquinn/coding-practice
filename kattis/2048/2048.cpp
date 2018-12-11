/*
IN PROGRESS

Author: Brandan Quinn
Problem: Develop 2048 game
URL: https://open.kattis.com/problems/2048
*/

#include <iostream>
#include <algorithm>

using namespace std;

// Generate a default 2048 board
void default_board(int board[4][4]);

// Generate a board of 2s
void twos_board(int board[4][4]);

// Print game board
void print_board(int board[4][4]);

// Move left and merge tiles accordingly.
void move_left(int board[4][4]);

// Assess a single row of tiles while moving left.
void assess_row_left(int row[4], int index);

// Move right and merge tiles accordingly.
void move_right(int board[4][4]);

// Assess a single row of tiles while moving right.
void assess_row_right(int row[4], int index);

// Move up and merge tiles accordingly.
void move_up(int board[4][4]);

// Assess a single column of tiles while moving up.
void assess_column_up(int col[4], int index);

int main() {
    int board[4][4];

    twos_board(board);

    int input;

    while (true) {
        print_board(board);

        cout << "Enter a move input (0: left), (1: up), (2: right), (3: down), (-1: exit): ";
        cin >> input;

        switch(input) {
            case -1:
                cout << "Thanks for playing. Good-bye." << endl;
                return 0;
                break;
            case 0:
                move_left(board);
                break;
            case 1:
                move_up(board);
                break;
            case 2:
                move_right(board);
                break;
            default:
                cout << "Invalid input. Try again." << endl;
                break;
        }
    }
}


void default_board(int board[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (i == 3 && (j == 0 || j == 1)) {
                board[i][j] = 2;
            } else {
                board[i][j] = 0;
            }
        }
    }
}

void twos_board(int board[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            board[i][j] = 2;
        }
    }
}

void print_board(int board[4][4]) {
    cout << "------------------" << endl;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

void move_left(int board[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 3; j >= 0; j--) {
            if (board[i][j] != 0) {
                assess_row_left(board[i], j);
            }
        }
    }
}

void assess_row_left(int row[4], int index) {
    for (int i = index-1; i >= 0; i--) {
        if (row[i] == 0) {
            swap(row[i], row[i+1]);
        } else {
            row[i] += row[i+1];
            row[i+1] = 0;
        }
    }
}

void move_right(int board[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] != 0) {
                assess_row_right(board[i], j);
            }
        }
    }
}

void assess_row_right(int row[4], int index) {
    for (int i = index+1; i < 4; i++) {
        if (row[i] == 0) {
            swap(row[i], row[i-1]);
        } else {
            row[i] += row[i-1];
            row[i-1] = 0;
        }
    }
}

void move_up(int board[4][4]) {
    for (int i = 3; i >= 0; i--) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] != 0) {
                assess_row_left(board[j], i);
            }
        }
    }
}