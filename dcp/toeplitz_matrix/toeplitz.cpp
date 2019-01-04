// This problem was asked by Google.

// In linear algebra, a Toeplitz matrix is one in which the elements on any given diagonal from top left to bottom right are identical.

// Here is an example:

// 1 2 3 4 8
// 5 1 2 3 4
// 4 5 1 2 3
// 7 4 5 1 2
// Write a program to determine whether a given input is a Toeplitz matrix.

#include <iostream>

using namespace std;

#define ROW 4
#define COL 5

bool check_diagonal(int mx[ROW][COL], int x, int y) {
    while (x < ROW-1 && y < COL-1) {
        if (mx[x][y] == mx[x+1][y+1]) {
            x++;
            y++;
        } else {
            return false;
        }
    }
    return true;
}
// main diagonal indices are: mx[0][0], mx[1][1], mx[2][2] -> mx[ROW-1][ROW-1]
// diagonal at: mx[0][1], mx[1][2], mx[2][3], x and y continue to increase until one or both reach ROW-1
bool is_toeplitz(int mx[ROW][COL]) {
    for (int i = 0; i < ROW; i++) {
        if (!check_diagonal(mx, i, 0))
            return false;
    }

    for (int j = 0; j < COL; j++) {
        if (!check_diagonal(mx, 0, j))
            return false;
    }

    return true;
}

int main() {
    int mx[ROW][COL] = {
        {1, 2, 3, 4, 8},
        {5, 1, 2, 3, 4},
        {4, 5, 1, 2, 3},
        {7, 4, 5, 1, 2}
    };

    if (is_toeplitz(mx))
        cout << "This is a toeplitz matrix." << endl;
    else
        cout << "This is not a toeplitz matrix" << endl;


    // for (int i = 0; i < ROW; i++) {
    //     for (int j = 0; j < COL; j++) {
    //         cout << mx[i][j] << " ";
    //     }
    //     cout << endl;
    // }
}