/*
f(i,buy,left) => maximum profit you can achieve starting day i, with buy status =buy(1 means can buy and currently empty 0 means cannot buy and currently full) with left number of transactions left

    if (left<=0) return 0
    if (i==n) return 0
    if (buy==0)
        sell=prices[i]+f(i+1,1,left-1)
        dontsell=f(i+1,0,left)
        return max sell dontsell
    else
        buy=-prices[i]+f(i+1,0,left)
        dontbuy=f(i+1,1,left)
        return max buy dont buy

*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3)));
        for (int i=0;i<=n;i++){
            for (int j=0;j<2;j++){
                dp[i][j][0]=0;
            }
        }
        for (int i=0;i<2;i++){
            for (int j=0;j<3;j++){
                dp[n][i][j]=0;
            }
        }
        for (int i=n-1;i>=0;i--){
            for (int buy=0;buy<2;buy++){
                for (int left=1;left<3;left++){
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
        return dp[0][1][2];
    }
};
