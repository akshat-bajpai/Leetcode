class Solution {
public:
    void helper(int i, string digits, string curr, vector<string>& ans, map<int,string> &mpp){
        if (i==digits.size()){
            ans.push_back(curr);
            return;
        }
        for (int j=0;j<mpp[digits[i]-'0'].size();j++){
            helper(i+1,digits,curr+mpp[digits[i]-'0'][j],ans,mpp);
        }
    }
    vector<string> letterCombinations(string digits) {
        map<int,string> mpp;
        mpp[2]="abc";
        mpp[3]="def";
        mpp[4]="ghi";
        mpp[5]="jkl";
        mpp[6]="mno";
        mpp[7]="pqrs";
        mpp[8]="tuv";
        mpp[9]="wxyz";
        vector<string> ans;
        string curr="";
        helper(0,digits,curr,ans,mpp);
        return ans;
    }
};
