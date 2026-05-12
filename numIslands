class Solution {
public:
    void bfs(vector<vector<char>>& grid, vector<vector<int>>& vis, int i, int j  ){
        vector<int> dr={1,-1,0,0};
        vector<int> dy={0,0,1,-1};
        vis[i][j]=1;
        queue<pair<int,int>>q;
        q.push({i,j});
        while (!q.empty()){
            pair<int,int> p=q.front();
            q.pop();
            for (int i=0;i<4;i++){
                int nrow=p.first+dr[i];
                int ncol=p.second+dy[i];
                if (nrow<0 || ncol<0 || nrow>=vis.size() || ncol>=vis[0].size()|| vis[nrow][ncol]==1 || grid[nrow][ncol]=='0') continue;
                vis[nrow][ncol]=1;
                q.push({nrow,ncol});
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        vector<vector<int>> vis(m,vector<int>(n,0));
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (vis[i][j]==0 && grid[i][j]=='1'){
                    bfs(grid,vis,i,j);
                    ans++;
                }
            }
        }
        return ans;
    }
};
