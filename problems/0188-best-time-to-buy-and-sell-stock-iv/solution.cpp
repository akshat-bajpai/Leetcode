class Solution {
public:
    int maxProfit(int limit, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(limit+1)));
        for (int i=0;i<=n;i++){
            for (int j=0;j<2;j++){
                dp[i][j][0]=0;
            }
        }
        for (int i=0;i<2;i++){
            for (int j=0;j<=limit;j++){
                dp[n][i][j]=0;
            }
        }
        for (int i=n-1;i>=0;i--){
            for (int j=0;j<2;j++){
                for (int k=1;k<limit+1;k++){
                    if (j==1){
                        dp[i][j][k]=max(dp[i+1][0][k]-prices[i], dp[i+1][j][k]);
                    }else{
                        dp[i][j][k]=max(dp[i+1][0][k],dp[i+1][1][k-1]+prices[i]);
                    }
                }
            }
        }

        return dp[0][1][limit];
    }   
};
