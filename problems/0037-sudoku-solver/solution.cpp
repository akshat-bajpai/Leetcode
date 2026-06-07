class Solution {
public:
    bool solve(vector<vector<char>>& board) {
        for (int i=0;i<9;i++){
            for (int j=0;j<9;j++){
                if (board[i][j]=='.'){
                    for (char num='1';num<='9';num++){
                        if (compatible(board,num,i,j)){
                            board[i][j]=num;
                            if (solve(board) ==true) return true;
                            board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool compatible(vector<vector<char>>& board, char num, int i, int j){
        for (int k=0;k<9;k++){
            if (board[i][k]==num) return false;

            if (board[k][j]==num) return false;

            if (board[3*(i/3)+k/3][3*(j/3)+k%3]==num) return false;

        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board){
        solve(board);
    }
};
