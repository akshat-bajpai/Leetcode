class Solution {
public:
    void bfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int i, int j){
        int m=grid.size();
        int n=grid[0].size();
        vector<int> dx={1,-1,0,0};
        vector<int> dy={0,0,1,-1};
        vis[i][j]=1;
        queue<pair<int,int>> q;
        q.push({i,j});
        while (!q.empty()){
            pair<int,int> p=q.front();
            q.pop();
            for (int i=0;i<4;i++){
                int nrow=p.first+dx[i];
                int ncol=p.second+dy[i];
                if (nrow<0 || ncol<0 || nrow>=m || ncol>=n || vis[nrow][ncol]==1 || grid[nrow][ncol]==0) continue;
                vis[nrow][ncol]=1;
                q.push({nrow,ncol});
            }
        }

    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        for (int i=0;i<m;i++){
            if (grid[i][0]==1) bfs(grid,vis,i,0);
            if (grid[i][n-1]==1) bfs(grid,vis,i,n-1);
        }
        for (int j=0;j<n;j++){
            if (grid[0][j]==1) bfs(grid,vis,0,j);
            if (grid[m-1][j]==1) bfs(grid,vis,m-1,j);
        }
        int ans=0;
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (grid[i][j]==1 && vis[i][j]==0) ans++;
            }
        }
        return ans;
    }
};
