class Solution {
public:
    bool isPalin(string a){
        string b=a;
        reverse(a.begin(),a.end());
        return a==b;
    }
    void helper(int i, string& s, vector<string> &curr, vector<vector<string>>& ans){
        if (i==s.size()){
            ans.push_back(curr);
            return;
        }
        for (int j=i;j<s.size();j++){
            if (isPalin(s.substr(i,j-i+1))){
                curr.push_back(s.substr(i,j-i+1));
                helper(j+1,s,curr,ans);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        helper(0,s,curr,ans);
        return ans;
    }   
};
