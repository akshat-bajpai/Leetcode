class Solution {
public:
    int longestPalindromeSubseq(string s) {
        //f(i,j)
        //  if (i==j) return 1
        //  if (i>j) return 0
        //  if s[i]==s[j] return 2+ f(i+1,j-1)
        //  leftNotTake=f(i+1,j)
        //  rightNotTake=f(i,j-1)
        //  return max(leftNotTake,rightNotTake)
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for (int i=0;i<n;i++){
            dp[i][i]=1;
        }
        for (int i=n-1;i>=0;i--){
            for (int j=i+1;j<n;j++){
                if (s[i]==s[j]) dp[i][j]=2+dp[i+1][j-1];
                else{
                int lnt=dp[i+1][j];
                int rnt=dp[i][j-1];
                dp[i][j]=max(lnt,rnt);
                }
            }
        }
        return dp[0][n-1];
    }
};
