class Solution {
public:
    void helper(int i, int k, int n, vector<int>& curr, vector<vector<int>>& ans){
        if (n==0 && k==0){
            ans.push_back(curr);
            return;
        }
        if (i==10 || k==0) return;
        curr.push_back(i);
        helper(i+1,k-1,n-i,curr,ans);
        curr.pop_back();
        helper(i+1,k,n,curr,ans);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> curr;
        vector<vector<int>> ans;
        helper(1,k,n,curr,ans);
        return ans;
    }
};
