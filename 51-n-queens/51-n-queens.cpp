class Solution {
public:
    vector<vector<string>> ans;
    bool isSafe(vector<string> &board,int row, int col)
    {
        int n=board.size();
        for(int i=0;i<col;i++)
        {
            if(board[row][i]=='Q')
                return false;
        }
        for(int i=row,j=col;i>=0&&j>=0;i--,j--)
        {
            if(board[i][j]=='Q')
                return false;
        }
        for(int i=row,j=col;j>=0&&i<n;i++,j--)
        {
            if(board[i][j]=='Q')
                return false;
        }
        return true;
    }
    void solve(vector<string> &board, int col){
        // exit condition
        if(col == board.size()){
            ans.push_back(board);
            return;
        }
        // iterate every possible position
        for(int i=0;i<board.size();i++){
            if(isSafe(board,i,col)){
                // make decision
                board[i][col] = 'Q';
                // next iteration
                solve(board,col+1);
                // back-tracking
                board[i][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        if(n <= 0) return {{}};
        vector<string> board(n,string(n,'.'));
        solve(board,0);
        return ans;
    }
};