class Solution {
public:
    int change(int amount, vector<int>& coins) {
        //dp[i][w]=combinations that make up W using coins upto index i
        int n=coins.size();
        vector<vector<unsigned long long>> dp(n,vector<unsigned long long>(amount+1,0));
        dp[0][0]=1;
        
        for (int i=0;i<=amount;i++){
            if (i%coins[0]==0) dp[0][i]=1;
        }

        for (int i=1;i<n;i++){
            for (int j=0;j<=amount;j++){
                unsigned long long notTake=dp[i-1][j];
                unsigned long long take=0;
                if (j-coins[i]>=0) take=dp[i][j-coins[i]];
                dp[i][j]=take+notTake;
            }
        }
        return dp[n-1][amount];
    }
};
