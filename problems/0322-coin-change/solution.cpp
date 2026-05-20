class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,INT_MAX);
        //dp[i]=minimum number of coints to makeup i amount
        dp[0]=0;
        for (int i=0;i<coins.size();i++){
            if (coins[i]<=amount) dp[coins[i]]=1;
            
        }
        for (int i=1;i<=amount;i++){
            int mini=dp[i];
            for (int j=0;j<coins.size();j++){
                if (i-coins[j]>=0 && dp[i-coins[j]]!=INT_MAX){
                    mini=min(mini,dp[i-coins[j]]+1);
                }
            }
            dp[i]=mini;
        }
        if (dp[amount]==INT_MAX) return -1;
        return dp[amount];
    }
};
