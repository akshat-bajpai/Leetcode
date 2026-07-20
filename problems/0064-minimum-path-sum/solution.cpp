class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        //dp[i][j]=min path from top left to i,j
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        dp[0][0]=grid[0][0];
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (i==0 && j==0) continue;
                int minSum=INT_MAX;
                if (i>0) minSum=min(minSum,grid[i][j]+dp[i-1][j]);
                if (j>0) minSum=min(minSum,grid[i][j]+dp[i][j-1]);
                dp[i][j]=minSum;
            }
        }
        return dp[m-1][n-1];
    }
};
