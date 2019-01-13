// Problem found here: https://leetcode.com/problems/set-matrix-zeroes/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> rows_to_zero;
        vector<int> cols_to_zero;
        
        for (int i = 0; i < (int)matrix.size(); i++) {
            for (int j = 0; j < (int)matrix[i].size(); j++) {
                if (matrix[i][j] == 0) {
                    rows_to_zero.push_back(i);
                    cols_to_zero.push_back(j);
                }
            }
        }
        
        // Remove duplicates
        vector<int>::iterator r;
        r = unique(rows_to_zero.begin(), rows_to_zero.end());
        rows_to_zero.resize(distance(rows_to_zero.begin(), r));
        
        vector<int>::iterator c;
        c = unique(cols_to_zero.begin(), cols_to_zero.end());
        cols_to_zero.resize(distance(cols_to_zero.begin(), c));
        
        // Zero out rows and columns found.
        for (int i = 0; i < (int)rows_to_zero.size(); i++)
            zero_rows(matrix, rows_to_zero[i]);
        for (int i = 0; i < (int)cols_to_zero.size(); i++)
            zero_cols(matrix, cols_to_zero[i]);
    }
    
    void zero_rows(vector<vector<int>> &matrix, int row) {
        for (int i = 0; i < (int)matrix[0].size(); i++) {
            matrix[row][i] = 0;
        }
    }
    
    void zero_cols(vector<vector<int>> &matrix, int col) {
        for (int i = 0; i < (int)matrix.size(); i++) {
            matrix[i][col] = 0;
        }
    }
};