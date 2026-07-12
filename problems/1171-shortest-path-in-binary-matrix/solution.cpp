class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if (grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        int dr[]={1,1,1,0,0,-1,-1,-1};
        int dc[]={1,0,-1,-1,1,-1,0,1};
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n,vector<int>(n,0));
        vis[0][0]=1;
        q.push({0,0});
        int len=0;
        while (!q.empty()){
            int s=q.size();
            len++;
            for (int i=0;i<s;i++){
                auto node=q.front();q.pop();
                if (node.first==n-1 && node.second==n-1) return len;
                for (int i=0;i<8;i++){
                    int nrow=node.first+dr[i];
                    int ncol=node.second+dc[i];
                    if (nrow>=0 && ncol>=0 && nrow<n && ncol<n && vis[nrow][ncol]==0 && grid[nrow][ncol]==0 ){
                        vis[nrow][ncol]=1;
                        q.push({nrow,ncol});
                    }
                }
            }
        }
        return -1;
    }
};
