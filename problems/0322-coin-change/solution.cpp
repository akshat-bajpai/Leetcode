class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //dp[x]=min number of coins required to make up x amount
        int n=coins.size();
        vector<int> dp(amount+1,1e9);
        for (int i=0;i<n;i++){
            if (coins[i]<=amount) dp[coins[i]]=1;
        }
        dp[0]=0;
        for (int i=1;i<=amount;i++){
            for (int j=0;j<coins.size();j++){
                if (i-coins[j]>=0) dp[i]=min(dp[i],dp[i-coins[j]]+1);
            }
        }
        return dp[amount]==1e9?-1:dp[amount];
    }
};
