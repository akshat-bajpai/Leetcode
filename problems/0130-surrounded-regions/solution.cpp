class Solution {
public:
    void bfs(vector<vector<char>>& board, vector<vector<int>>& vis, int i, int j){
        int m=board.size();
        int n=board[0].size();
        vector<int> dx={1,-1,0,0};
        vector<int> dy={0,0,1,-1};
        queue<pair<int,int>>q;
        q.push({i,j});
        vis[i][j]=1;
        while (!q.empty()){
            pair<int,int> p=q.front();
            q.pop();
            for (int i=0;i<4;i++){
                int nrow=p.first+dx[i];
                int ncol=p.second+dy[i];
                if (nrow<0 || ncol<0 || nrow>=m || ncol>=n || vis[nrow][ncol]==1 || board[nrow][ncol]=='X') continue;
                vis[nrow][ncol]=1;
                q.push({nrow,ncol});
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();

        vector<vector<int>> vis(m,vector<int>(n,0));

        for (int i=0;i<m;i++){
            if (board[i][0]=='O'){
                bfs(board,vis,i,0);
            }
            if (board[i][n-1]=='O'){
                bfs(board,vis,i,n-1);
            }
        }

        for (int j=0;j<n;j++){
            if (board[0][j]=='O'){
                bfs(board,vis,0,j);
            }
            if (board[m-1][j]=='O'){
                bfs(board,vis,m-1,j);
            }
        }

        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (board[i][j]=='O' && vis[i][j]==0) board[i][j]='X';
            }
        }
    }
};
