class Solution {
public:
    int minDistance(string word1, string word2) {
        //dp[i][j]=minimum operations required to convert word1 to word2
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1));
        for (int i=0;i<=n;i++){
            dp[i][0]=i;
        }
        for (int i=0;i<=m;i++){
            dp[0][i]=i;
        }
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                if (word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }else{
                    int rep=dp[i-1][j-1]+1;
                    int del=dp[i-1][j]+1;
                    int ins=dp[i][j-1]+1;
                    dp[i][j]=min(rep,min(del,ins));
                }
            }
        }
        return dp[n][m];
    }
};
