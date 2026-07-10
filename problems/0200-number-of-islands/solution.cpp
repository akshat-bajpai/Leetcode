class Solution {
public:
    void bfs(vector<vector<char>>& grid, vector<vector<int>>& vis, int i, int j){
        int m=grid.size();
        int n=grid[0].size();
        vis[i][j]=1;
        int dr[]={1,-1,0,0};
        int dc[]={0,0,1,-1};
        queue<pair<int,int>>q;
        q.push({i,j});
        while (!q.empty()){
            auto node=q.front();
            q.pop();
            for (int i=0;i<4;i++){
                int nrow=node.first+dr[i];
                int ncol=node.second+dc[i];
                if (nrow>=0 && ncol>=0 && nrow<m && ncol<n && vis[nrow][ncol]==0 && grid[nrow][ncol]=='1'){
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=1;
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int num=0;
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (grid[i][j]=='1' && vis[i][j]==0){
                    num++;
                    bfs(grid,vis,i,j);
                }
            }
        }
        return num;
    }
};
