class Solution {
public:
    void helper(int i, int n, string temp, vector<string>& ans, int last){
        if (i==n){
            ans.push_back(temp);
            return;
        }
        if (last==0){
            temp[i]='1';
            helper(i+1,n,temp,ans,1);
        }else{
            temp[i]='0';
            helper(i+1,n,temp,ans,0);
            temp[i]='1';
            helper(i+1,n,temp,ans,1);
        }
    }
    vector<string> validStrings(int n) {
        vector<string> ans;
        string temp(n, ' ');
        helper(0,n,temp,ans,1);
        return ans;
    }
};
