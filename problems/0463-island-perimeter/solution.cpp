class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        int dr[]={1,-1,0,0};
        int dc[]={0,0,1,-1};
        int perimeter=0;
        vector<vector<int>> vis(row,vector<int>(col,0));
        queue<pair<int,int>> q;
        for (int i=0;i<row;i++){
            for (int j=0;j<col;j++){
                if (grid[i][j]==1){
                    vis[i][j]=1;
                    q.push({i,j});
                    while (!q.empty()){
                        auto node=q.front();
                        q.pop();
                        for (int dir=0;dir<4;dir++){
                            int nrow=node.first+dr[dir];
                            int ncol=node.second+dc[dir];
                            if (nrow>=0 && ncol>=0 && nrow<row && ncol<col && vis[nrow][ncol]==0 && grid[nrow][ncol]==1){
                                q.push({nrow,ncol});
                                vis[nrow][ncol]=1;
                            }else{
                                if (nrow<0||nrow>=row||ncol<0||ncol>=col||grid[nrow][ncol]==0) {
                                    perimeter++;
                                }
                            }
                        }
                    }
                    return perimeter;
                }
                
            }
        }
        return perimeter;
    }
};
