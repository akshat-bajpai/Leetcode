class Solution {
public:
    void helper(int i, vector<int>& candidates, int target, vector<int>& curr, int sum, vector<vector<int>>& ans){
        if (sum==target){
            ans.push_back(curr);
            return;
        }
        if (sum>target || i==candidates.size()) return;
        curr.push_back(candidates[i]);
        sum+=candidates[i];
        helper(i,candidates,target,curr,sum,ans);
        curr.pop_back();
        sum-=candidates[i];
        helper(i+1,candidates,target,curr,sum,ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> st;
        vector<int> curr;
        helper(0,candidates,target,curr,0,st);
        return st;
    }
};
