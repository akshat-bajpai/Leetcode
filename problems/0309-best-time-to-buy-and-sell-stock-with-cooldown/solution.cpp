/*
f(i,buy) => max profit with buy status = buy (1 means can buy and dont hold anything, 0 means cannot buy and holding onto something) starting day i

    if (i==n) return 0;

    if (buy==1){
        buy=-prices[i]+f(i+1,0)
        dontbuy=f(i+1,1)
    }else{
        sell=prices[i];
        if (i<n-1) sell+=f(i+2,1);
        dontsell=f(i+1,0);
    }
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        for (int i=n-1;i>=0;i--){
            for (int j=0;j<2;j++){
                if (j==1){
                    int buy=-prices[i]+dp[i+1][0];
                    int dontbuy=dp[i+1][1];
                    dp[i][j]=max(buy,dontbuy);
                }else{
                    int sell=prices[i];
                    if (i<n-1) sell+=dp[i+2][1];
                    int dontsell=dp[i+1][0];
                    dp[i][j]=max(sell,dontsell);
                }
            }
        }
        return dp[0][1];
    }
};
