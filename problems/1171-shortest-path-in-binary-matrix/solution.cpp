class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // 1,1 1,0 1,-1 0,1 0,-1 -1,0 -1,-1 -1,1
        if (grid[0][0]==1) return -1;
        int n=grid.size();
        vector<int> drow={1,1,1,0,0,-1,-1,-1};
        vector<int> dcol={1,0,-1,1,-1,0,-1,1};
        //BFS
        int length=1;
        queue<pair<int,int>> q;
        q.push({0,0});
        vector<vector<int>> vis (n,vector<int> (n,0));
        vis[0][0]=1;
        while (!q.empty()){
            int s=q.size();
            for (int j=0;j<s;j++){
                int r=q.front().first;
                int c=q.front().second;
                q.pop();
                if (r==n-1 && c==n-1) return length;
                for (int i=0;i<8;i++){
                    int nrow=r+drow[i];
                    int ncol=c+dcol[i];
                    if (nrow<0 || ncol<0 || nrow>=n || ncol >=n || grid[nrow][ncol]==1 || vis[nrow][ncol]==1) continue;
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
            length++;
        }
        return -1;
    }
};
