class Solution {
public:
    static bool comp(string a, string b){
        return a.size()<b.size();
    }
    bool isPredecessor(string a, string b){
        if (a.size()!=b.size()-1) return false;
        int n=b.size();
        int i=0;
        int j=0;
        while (j<n){
            if (a[i]==b[j]){
                i++;
                j++;
            }else{
                j++;
            }
        }
        if (i==n-1) return true;
        return false;
    }
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(),words.end(), comp);
        vector<int> dp(n,1);
        int maxi=0;
        for (int i=0;i<n;i++){
            for (int prev=0;prev<i;prev++){
                if (isPredecessor(words[prev],words[i]) && dp[i]<dp[prev]+1){
                    dp[i]=dp[prev]+1;
                }
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;

    }
};
