//37. 解数独
// Created by Administrator on 2020/5/11 0011.
//

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> rowUsed(9, vector<bool>(10, false));
        vector<vector<bool>> colUsed(9, vector<bool>(10, false));
        vector<vector<vector<bool>>> blockUsed(3, vector<vector<bool>>(3, vector<bool>(10, false)));
        for(int i = 0; i < 9; ++i){
            for(int j = 0; j < 9; ++j){
                if(board[i][j] != '.'){
                    int num = board[i][j] - '0';
                    rowUsed[i][num] = true;
                    colUsed[j][num] = true;
                    blockUsed[i/3][j/3][num] = true;
                }
            }
        }
        dfs(board, rowUsed, colUsed, blockUsed, 0, 0);
        return ;
    }

    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& rowUsed, vector<vector<bool>>& colUsed, vector<vector<vector<bool>>>& blockUsed, int row, int col){
        if(col == 9){
            row++;
            col = 0;
            if(row == 9){
                return true;
            }
        }
        if(board[row][col] == '.'){
            for(int i = 1; i <= 9; ++i){
                if(rowUsed[row][i] || colUsed[col][i] || blockUsed[row/3][col/3][i]) continue;
                board[row][col] = (char)(i+'0');
                rowUsed[row][i] = true;
                colUsed[col][i] = true;
                blockUsed[row/3][col/3][i] = true;
                if(dfs(board, rowUsed, colUsed, blockUsed, row, col+1)){
                    return true;
                }else{
                    board[row][col] = '.';
                    rowUsed[row][i] = false;
                    colUsed[col][i] = false;
                    blockUsed[row/3][col/3][i] = false;
                }
            }
        }else{
            return dfs(board, rowUsed, colUsed, blockUsed, row, col+1);
        }
        return false;
    }
};