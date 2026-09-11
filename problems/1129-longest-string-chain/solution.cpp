class Solution {
public:
    static bool comp(string a, string b){
        return a.size()<b.size();
    }
    bool validPair(string word1, string word2){
        if (word1.size()>=word2.size()) return false;
        int i=0;
        for (int j=0;j<word2.size();j++){
            if (word1[i]==word2[j]){
                i++;
            }
        }
        if (i==word2.size()-1) return true;
        return false;
    }
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(),words.end(),comp);
        vector<int> dp(n,1);
        int largest=1;
        for (int i=1;i<n;i++){
            for (int j=0;j<i;j++){
                if (validPair(words[j],words[i])){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            largest=max(largest,dp[i]);
        }
        return largest;
    }
};
