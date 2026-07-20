class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int>(n));
        dp[0][0]=triangle[0][0];
        for (int i=1;i<n;i++){
            for (int j=0;j<=i;j++){
                int minSum=INT_MAX;
                if (j!=0) minSum=min(minSum,triangle[i][j]+dp[i-1][j-1]);
                if (j!=i) minSum=min(minSum,triangle[i][j]+dp[i-1][j]);
                dp[i][j]=minSum;
            }
        }
        int ans=dp[n-1][0];
        for (int i=0;i<n;i++){
            ans=min(dp[n-1][i],ans);
        }
        return ans;
    }
};
