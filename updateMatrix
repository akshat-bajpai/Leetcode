class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        vector<vector<int>>dist(m,vector<int>(n,0));
        queue<pair<int,int>>q;
        vector<int> drow={1,-1,0,0};
        vector<int> dcol={0,0,1,-1};
        int d=0;
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (mat[i][j]==0) {
                    q.push({i,j});
                    vis[i][j]=1;
                }
            }
        }
        while (!q.empty()){
            int qs=q.size();
            for (int i=0;i<qs;i++){
                pair<int,int> f=q.front();
                q.pop();
                dist[f.first][f.second]=d;
                for (int i=0;i<4;i++){
                    int nrow=f.first+drow[i];
                    int ncol=f.second+dcol[i];
                    if (nrow<0 || ncol<0 || nrow>=m || ncol>=n || vis[nrow][ncol]==1)continue;
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=1;
                }
            }
            d++;
        }
        return dist;
    }
};
