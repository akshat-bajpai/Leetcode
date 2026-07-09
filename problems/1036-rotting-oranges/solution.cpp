class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int dr[]={1,-1,0,0};
        int dc[]={0,0,1,-1};
        int total=0;
        int rotten=0;
        vector<vector<int>> vis(m,vector<int>(n,0));
        queue<pair<int,int>> q;
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (grid[i][j]==1){
                    total++;
                }else if (grid[i][j]==2){
                    total++;
                    vis[i][j]=1;
                    q.push({i,j});
                }
            }
        }
        if (total==0) return 0;
        
        int time=-1;
        while (!q.empty()){
            time++;
            int s=q.size();
            for (int i=0;i<s;i++){
                auto node=q.front();
                rotten++;
                q.pop();
                for (int i=0;i<4;i++){
                    int nrow=node.first+dr[i];
                    int ncol=node.second+dc[i];
                    if (nrow>=0 && ncol>=0 && nrow<m && ncol<n && vis[nrow][ncol]==0 && grid[nrow][ncol]==1) {
                        q.push({nrow,ncol});
                        vis[nrow][ncol]=1;
                    }
                }
            }
        }
        if (rotten==total) return time;
        return -1;
    }
};
