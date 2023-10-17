#include <bits/stdc++.h>
using namespace std;

// Valid Sudoku

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool cnt1[10][10] = {0}, cnt2[10][10] = {0}, cnt3[10][10] = {0};
        

        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] != '.') {
                    int num = board[i][j] - '0';
                    int k = i / 3 * 3 + j / 3;
                    if(cnt1[i][num] || cnt2[j][num] || cnt3[k][num]) return false;
                    cnt1[i][num] = cnt2[j][num] = cnt3[k][num] = 1;
                }
            }
        }
        
        return true;
    }
};