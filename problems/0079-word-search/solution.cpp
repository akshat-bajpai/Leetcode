class Solution {
public:
    bool helper(vector<vector<char>>& board, string& word, int i,int j, int ind, vector<vector<int>>& vis){
        if (ind==(word.size()-1) && word[ind]==board[i][j]){
            return true;
        }
        vis[i][j]=1;
        int dr[4]={1,-1,0,0};
        int dc[4]={0,0,1,-1};
        for (int p=0;p<4;p++){
            int nrow=i+dr[p];
            int ncol=j+dc[p];
            if (nrow<0 || ncol<0 || nrow>=board.size() || ncol>=board[0].size() || vis[nrow][ncol]==1 || board[nrow][ncol]!=word[ind+1]) continue;
            if (helper(board,word,nrow,ncol,ind+1,vis)) return true;
        }
        vis[i][j]=0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (board[i][j]==word[0]){
                    if (helper(board,word,i,j,0,vis)) return true;
                }
            }
        }
        return false;

    }
};
