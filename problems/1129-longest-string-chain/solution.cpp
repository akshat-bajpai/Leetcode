class Solution {
public:
    static bool comp(string a, string b){
        return a.size()<b.size();
    }
    bool isValid(string a, string b){
        if (a.size()!=b.size()-1) return false;
        int n=b.size();
        int i=0,j=0;
        while (j<n){
            if (a[i]==b[j]){
                i++;j++;
            }else{
                j++;
            }
        }
        if (i==a.size()) return true;
        return false;
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),comp);
        int n=words.size();
        vector<int> dp(n,1);
        int maxi=1;
        for (int i=0;i<n;i++){
            for (int j=0;j<i;j++){
                if (isValid(words[j],words[i])){
                    if (dp[i]<dp[j]+1){
                        dp[i]=dp[j]+1;
                    }
                }
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
};
