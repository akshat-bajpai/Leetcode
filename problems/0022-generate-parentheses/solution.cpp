class Solution {
public:
    void helper(vector<string> &ans, int i, int n, int open, string cur, int close){
        if (i==2*n){
            ans.push_back(cur);
            return;
        }
        if (open-close==0){
            cur[i]='(';
            helper(ans,i+1,n,open+1,cur,close);
            return;
        }
        //open>close
        if (open<n){
            cur[i]='(';
            helper(ans,i+1,n,open+1,cur,close);
        }
        cur[i]=')';
        helper(ans,i+1,n,open,cur,close+1);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string cur(2*n,' ');
        helper(ans,0,n,0,cur,0);
        return ans;
    }
};
