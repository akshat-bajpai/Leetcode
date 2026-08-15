/*
f(i,buy) => maximum profit achieved starting day i with (buy==1)? can buy and dont hold stock : cannot buy and holding stock
    if (i==n-1)
        if (buy==0) return prices[i]
        else return 0
    if (buy==0)
        sell=prices[i]+f(i+1,1)
        dontsell=f(i+1,0)
        return max(sell,notsell)

    else
        buy=-prices[i]+f(i+1,0)
        dontbuy=f(i+1,1)
        return max(buy,notbuy)
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2));
        for (int i=0;i<n;i++){
            dp[i][0]=prices[i];
            dp[i][1]=0;
        }
        for (int i=n-2;i>=0;i--){
            for (int j=0;j<2;j++){
                if (j==0){
                    dp[i][j]=max(prices[i]+dp[i+1][1],dp[i+1][0]);
                }else{
                    dp[i][j]=max(-prices[i]+dp[i+1][0],dp[i+1][1]);
                }
            }
        }
        return dp[0][1];
    }
};
