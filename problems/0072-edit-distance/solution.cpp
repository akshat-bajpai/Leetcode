/*
f(i,j) => min ops to convert word1[0...i] to word2[0...j]

    if (i<0 || j<0) 
        return max(i,j)+1
    if (word1[i]==word2[j]) return f(i-1,j-1)
    else
        insert=1+f(i,j-1)
        delete=1+f(i-1,j)
        rplace=1+f(i-1,j-1)
        return min(insert,delete,replace)
*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1=word1.size();
        int n2=word2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        for (int i=0;i<=n1;i++){
            dp[i][0]=i;
        }
        for (int i=0;i<=n2;i++){
            dp[0][i]=i;
        }
        for (int i=1;i<=n1;i++){
            for (int j=1;j<=n2;j++){
                if (word1[i-1]==word2[j-1]) dp[i][j]=dp[i-1][j-1];
                else{
                    int r=1+dp[i-1][j-1];
                    int d=1+dp[i-1][j];
                    int in=1+dp[i][j-1];
                    dp[i][j]=min(r,min(d,in));
                }
            }
        }
        return dp[n1][n2];
    }
};
