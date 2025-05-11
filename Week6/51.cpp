class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        solve(0, board, result, n);
        return result;
    }

    // current(cur) = 現在
    void solve(int cur_row, vector<string>& board, vector<vector<string>>& result, int n) {
        if (cur_row == n) {
            result.push_back(board);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (isSafe(cur_row, col, board, n)) {
                board[cur_row][col] = 'Q';
                solve(cur_row + 1, board, result, n);
                board[cur_row][col] = '.'; // backtrack
            }
        }
    }

    bool isSafe(int row, int col, vector<string>& board, int n){
        for(int i = 0; i < row; i++){ //同一列
            if(board[i][col] == 'Q') 
                return false;
        }
        for(int i = row - 1, j = col - 1; i >= 0 && j >=0; i--, j--){ //左上對角
            if(board[i][j] == 'Q') 
                return false;
        }
        for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++){ //右上對角
            if(board[i][j] == 'Q') 
                return false;
        }

        return true;
    }
};