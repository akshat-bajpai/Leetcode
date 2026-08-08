class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        //f(i,j) lengthof longest common subsequence of text1[0..i] && text2[0...j]
        //  if (i==-1 || j==-1) return 0
        //  not match=max(f(i-1,j),f(i,j-1))
        //  match=0
        // if (text1[i]==text2[j]) match=1+f(i-1,j-1)
        // return max(match, notMatch)
        int n1=text1.size();
        int n2=text2.size();

        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        for (int i=1;i<=n1;i++){
            for (int j=1;j<=n2;j++){
                int notMatch=max(dp[i-1][j],dp[i][j-1]);
                int match=0;
                if (text1[i-1]==text2[j-1]) match=1+dp[i-1][j-1];
                dp[i][j]=max(match,notMatch);
            }
        }
        return dp[n1][n2];
    }
};
