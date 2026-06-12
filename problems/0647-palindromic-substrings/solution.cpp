class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        vector<vector<bool>> dp(n, vector<bool>(n,false));
        // for (int i=0;i<n;i++){
        //     dp[i][i]=true;
        // }
        // for (int i=n-1;i>=0;i--){
        //     for (int j=i+1;j<n;j++){
        //         if (s[i]==s[j]){
        //             if (j==i+1){
        //                 dp[i][j]=true;
        //                 continue;
        //             }
        //             dp[i][j]=dp[i+1][j-1];
        //         }
        //     }
        // }
        for (int len=1;len<=n;len++){
            for (int i=0;i<n;i++){
                int j=i+len-1;
                if (j>=n) continue;
                if (s[i]==s[j]){
                    if (i==j || j==i+1){
                        dp[i][j]=true;
                    }else{
                        dp[i][j]=dp[i+1][j-1];
                    }
                }
            }
        }
        int count=0;
        for (int i=0;i<n;i++){
            for (int j=i;j<n;j++){
                if (dp[i][j]) count++;
            }
        }
        return count;

    }
};
