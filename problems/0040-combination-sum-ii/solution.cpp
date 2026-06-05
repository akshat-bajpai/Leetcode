class Solution {
public:
    void helper(int i, vector<int>& candidates, int target, vector<int>& curr, vector<vector<int>>& ans){
        if (target==0){
            ans.push_back(curr);
            return;
        }
        if (i==candidates.size() || target<0) return;
        for (int j=i;j<candidates.size();j++){
            if (j>i && candidates[j]==candidates[j-1]) continue;
            curr.push_back(candidates[j]);
            helper(j+1,candidates,target-candidates[j],curr,ans);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> curr;
        helper(0,candidates,target,curr,ans);
        return ans;
    }
};
