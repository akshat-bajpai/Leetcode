class Solution {
public:
    bool safe(vector<string>& board, int col, int row){
        int ogr=row;
        int oc=col;

        while(row>=0 && col>=0){
            if (board[row][col]=='Q'){
                return false;
            }
            row--;
            col--;
        }

        row=ogr;
        col=oc;

        while(col>=0){
            if(board[row][col]=='Q'){
                return false;
            }
            col--;
        }

        col=oc;

        while(col>=0 && row<board.size()){
            if (board[row][col]=='Q'){
                return false;
            }
            row++;
            col--;
        }
        return true;
    }
    void helper(int col, vector<vector<string>>& ans, vector<string>& board,int n){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for (int i=0;i<n;i++){
            if(safe(board,col,i)){
                board[i][col]='Q';
                helper(col+1,ans,board,n);
                board[i][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string s(n,'.');
        vector<string> board(n,s);
        helper(0,ans,board,n);
        return ans;
    }
};
