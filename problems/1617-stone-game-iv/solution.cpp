class Solution {
public:
    bool winnerSquareGame(int n) {
        //dp[n]=true if player can win with n stones i.e. there exists dp[i-x*x]=false
        vector<int> dp(n+1);
        dp[0]=false;
        for (int i=1;i<=n;i++){
            for (int j=1;j*j<=i;j++){
                int sq=j*j;
                if (dp[i-sq]==false) dp[i]=true;
            }
        }
        return dp[n];
    }
};
