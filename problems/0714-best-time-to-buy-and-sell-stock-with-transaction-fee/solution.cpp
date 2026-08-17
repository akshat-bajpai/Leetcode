class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        for (int i=n-1;i>=0;i--){
            for (int j=0;j<2;j++){
                if (j==1){
                    int buy=-prices[i]+dp[i+1][0]-fee;
                    int dontbuy=dp[i+1][1];
                    dp[i][j]=max(buy,dontbuy);
                }else{
                    int sell=prices[i]+dp[i+1][1];
                    int dontsell=dp[i+1][0];
                    dp[i][j]=max(sell,dontsell);
                }
            }
        }
        return dp[0][1];
    }
};
