class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<int>prev(n,0);
        //DP[i][j]= minimum sum to reach i,j
        for (int i=0;i<m;i++){
            vector<int> curi(n,0);
            for (int j=0;j<n;j++){
                if (i==0 && j==0){
                    curi[j]=grid[0][0];
                    continue;
                }
                int up=INT_MAX,left=INT_MAX;
                if (i-1>=0) up=prev[j];
                if (j-1>=0) left=curi[j-1];
                curi[j]=min(up,left)+grid[i][j];
            }
            prev=curi;
        }
        return prev[n-1];
    }
};
