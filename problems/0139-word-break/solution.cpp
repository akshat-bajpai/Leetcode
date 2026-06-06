class Solution {
public:
    bool helper(string& s,int i,  set<string>& wordDict, vector<int>& dp){
        if (i==s.size()) return true;
        if (dp[i]!=-1) return dp[i];
        for (int j=i;j<s.size();j++){
            if (wordDict.find(s.substr(i,j-i+1))!=wordDict.end()){
                if (helper(s,j+1,wordDict,dp)) return dp[i]= true;
            }
        }
        return dp[i]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st( wordDict.begin(),wordDict.end());
        vector<int> dp(s.size(),-1);
        return helper(s,0,st,dp);
    }
};
