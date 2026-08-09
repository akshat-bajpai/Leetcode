class Solution {
public:
    int minInsertions(string s) {
        //f(i,j) ==> min number of insertions to make s[i...j] a palindrome
        //  if (i>=j) return 0
        //
        //  if (s[i]==s[j]) return f(i+1,j-1)
        //  else return 1+min(f(i+1,j),f(i,j-1))
        int n=s.size(); 
        vector<vector<int>> dp(n,vector<int>(n,0));
        for (int i=n-1;i>=0;i--){
            for (int j=i+1;j<n;j++){
                if (s[i]==s[j]) dp[i][j]=dp[i+1][j-1];
                else dp[i][j]=1+min(dp[i+1][j],dp[i][j-1]);
            }
        }     
        return dp[0][n-1];           
    }
};
