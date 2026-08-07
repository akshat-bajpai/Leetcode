class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //dp[i][j]=min number of coins to make j amount using coins till index i
        int n=coins.size();
        vector<int> prev(amount+1), cur(amount+1);
        for (int i=0;i<=amount;i++){
            if (i%coins[0]==0) prev[i]=i/coins[0];
            else prev[i]=INT_MAX;
        }
        cur=prev;
        for (int i=1;i<n;i++){
            for (int j=0;j<=amount;j++){
                int notTake=prev[j];
                int take=INT_MAX;
                if (j-coins[i]>=0 && cur[j-coins[i]]!=INT_MAX) take=1+cur[j-coins[i]];
                cur[j]=min(take,notTake);
            }
            prev=cur;
        }
        return prev[amount]==INT_MAX?-1:prev[amount];
    }
};
