class Solution {
public:
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int r, int c){
        if (vis[r][c]==1) return;
        int m=grid.size();
        int n=grid[0].size();
        vis[r][c]=1;
        int dr[]={1,-1,0,0};
        int dc[]={0,0,1,-1};
        for (int i=0;i<4;i++){
            int nrow=r+dr[i];
            int ncol=c+dc[i];
            if (nrow>=0 && ncol>=0 && nrow<m && ncol<n && vis[nrow][ncol]==0 && grid[nrow][ncol]==1){
                dfs(grid,vis,nrow,ncol);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        for (int i=0;i<m;i++){
            if (grid[i][0]==1){
                dfs(grid,vis,i,0);
            }
            if (grid[i][n-1]==1){
                dfs(grid,vis,i,n-1);
            }
        }
        for (int i=0;i<n;i++){
            if (grid[0][i]==1){
                dfs(grid,vis,0,i);
            }
            if (grid[m-1][i]){
                dfs(grid,vis,m-1,i);
            }
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
