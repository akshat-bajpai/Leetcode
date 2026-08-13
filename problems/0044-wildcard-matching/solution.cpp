/*
f(i,j) => true if s[0...i] and p[0...j] match otherwise false

    if (s[i]==p[j]) return f(i-1,j-1)
    else
        if (p[j]=='?')
            return f(i-1,j-1)
        if (p[j]=='*)
            return f(i-1,j)
        else 
            return false
*/
class Solution {
public:
    bool isMatch(string s, string p) {
        int n1=s.size();
        int n2=p.size();
        vector<vector<bool>> dp(n1+1,vector<bool>(n2+1));
        dp[0][0]=true;
        for (int i=1;i<=n1;i++){
            dp[i][0]=false;
        }
        bool check=true;
        for (int i=1;i<=n2;i++){
            if (p[i-1]!='*') check=false;
            dp[0][i]=check;
        }
        for (int i=1;i<=n1;i++){
            for (int j=1;j<=n2;j++){
                if (s[i-1]==p[j-1]) dp[i][j]=dp[i-1][j-1];
                else{
                    if (p[j-1]=='?') dp[i][j]=dp[i-1][j-1];
                    else if (p[j-1]=='*') dp[i][j]=dp[i-1][j]||dp[i][j-1];
                    else dp[i][j]=false;
                }
            }
        }
        return dp[n1][n2];
    }
};
