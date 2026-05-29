class Solution {
public:
    int minCut(string& s) {
        int n=s.size();
        vector<int> dp(n+1,0);
        vector<vector<int>> pal(n,vector<int>(n,0));
        for (int i=n-1;i>=0;i--){
            for (int j=i;j<n;j++){
                if (s[i]==s[j]){
                    if (j-i<=2 || pal[i+1][j-1]){
                        pal[i][j]=1;
                    }
                }
            }

        }
        //dp[i]=min cuts for palindrome partitioning of s starting index i
        for (int i=n-1;i>=0;i--){
            int mini=1e9;
            for (int j=i;j<n;j++){
                if (pal[i][j]){
                    mini=min(mini,1+dp[j+1]);
                }
            }
            dp[i]=mini;
        }
        return dp[0]-1;
    }
};
