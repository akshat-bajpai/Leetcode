class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n=s.size();
        vector<vector<bool>> isP(n,vector<bool>(n,false));
        for (int i=0;i<n;i++) isP[i][i]=true;
        //f(i,j) if (s[i]==s[j]) if length=2 return true else return f(i+1,j-1)
        for (int i=n-1;i>=0;i--){
            for (int j=i+1;j<n;j++){
                if (s[i]==s[j]){
                    if (j==i+1) isP[i][j]=true;
                    else isP[i][j]=isP[i+1][j-1];
                }
            }
        }
        vector<int> dp(n,0); //dp[i]=maximum number of substrings in s[0...i] which are palindromic with length atleast k
        for (int i=k-1;i<n;i++){
            //2 cases
            //the index results in formation of a new pallindromic substring
            //the index doesnt so skip it
            int notPick=(i==k-1?0:dp[i-1]);
            int pick=0;
            for (int j=0;j<=i-k+1;j++){
                if (isP[j][i]){
                    int temp;
                    if (j==0) temp=1;
                    else temp=1+dp[j-1];
                    pick=max(pick,temp);
                }
            }
            dp[i]=max(pick,notPick);
        }
        return dp[n-1];
    }
};
