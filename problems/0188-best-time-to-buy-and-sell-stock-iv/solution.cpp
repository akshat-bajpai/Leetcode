/*

*/

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        for (int i=n-1;i>=0;i--){
            for (int buy=0;buy<2;buy++){
                for (int left=1;left<=k;left++){
                    int profit=0;
                    if (buy==0){
                        profit=max(prices[i]+dp[i+1][1][left-1],dp[i+1][0][left]);
                    }else{
                        profit=max(-prices[i]+dp[i+1][0][left],dp[i+1][1][left]);

                    }
                    dp[i][buy][left]=profit;
                }
            }
        }
        return dp[0][1][k];
    }
};
