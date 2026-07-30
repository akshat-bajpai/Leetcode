class Solution {
public:
    int minInsertions(string s) {
        int n=s.size();
        //dp[i][j]=min number of steps to make s[i...j] a palindrome
        //f(i,j)
        //  if (i==j) returnn 0
        //  if (s[i]==s[j]) return f(i+1,j-1)
        //  int lnt=f(i+1,j)+1
        //  int rnt=f(i,j-1)+1
        // return min(lnt,rnt)
        vector<vector<int>> dp(n,vector<int>(n,0));
        for (int i=0;i<n;i++){
            dp[i][i]=0;
        }
        for (int i=n-1;i>=0;i--){
            for (int j=i+1;j<n;j++){
                if (s[i]==s[j]){
                    dp[i][j]=dp[i+1][j-1];
                }else{
                    int lnt=dp[i+1][j];
                    int rnt=dp[i][j-1];
                    dp[i][j]=min(lnt,rnt)+1;
                }
            }
        }
        return dp[0][n-1];
    }
};
