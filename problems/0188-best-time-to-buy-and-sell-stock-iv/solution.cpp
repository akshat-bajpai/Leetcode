class Solution {
public:
    int maxProfit(int limit, vector<int>& prices) {
        int n=prices.size();
        //dp[ind][buy_feasibility][transactions_completed]

        //f(ind,buy,tcount)
        //if (buy)
        //      f(ind+1,buy,tcount), f(ind+1,!buy,tcount)-prices[ind]
        //else 
        //      f(ind+1,buy,tcount), f(ind+1,!buy,tcount+1)+prices[ind]
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(limit+1)));

        for (int i=0;i<2;i++){
            for (int j=0;j<limit+1;j++){
                dp[n][i][j]=0;
            }
        }

        for (int i=n-1;i>=0;i--){
            for (int j=0;j<2;j++){
                for (int k=0;k<limit+1;k++){
                    if (j==1){
                        dp[i][j][k]=k==limit?dp[i+1][j][k] : max(dp[i+1][0][k]-prices[i], dp[i+1][j][k]);
                    }else{
                        dp[i][j][k]=k==limit?dp[i+1][0][k] : max(dp[i+1][0][k],dp[i+1][1][k+1]+prices[i]);
                    }
                }
            }
        }

        return dp[0][1][0];
    }   
};
