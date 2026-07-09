class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int dr[]={1,-1,0,0};
        int dc[]={0,0,1,-1};
        vector<vector<int>> vis(m,vector<int>(n,0));
        queue<pair<int,int>>q;
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (mat[i][j]==0){
                    vis[i][j]=1;
                    q.push({i,j});
                }
            }
        }
        int dist=0;
        while (!q.empty()){
            int s=q.size();
            for (int i=0;i<s;i++){
                auto node=q.front();
                q.pop();
                for (int i=0;i<4;i++){
                    int nrow=node.first+dr[i];
                    int ncol=node.second+dc[i];
                    if (nrow<0 || ncol<0 || nrow>=m || ncol>=n || vis[nrow][ncol]==1) continue;
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
                mat[node.first][node.second]=dist;
            }
            dist++;
        }
        return mat;
    }
};
