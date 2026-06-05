class Solution {
public:
    void helper(vector<vector<int>>& ans, vector<int>& curr, int i, vector<int>& nums){

        ans.push_back(curr);
        for (int j=i;j<nums.size();j++){
            if (j>i && nums[j]==nums[j-1]) continue;
            curr.push_back(nums[j]);
            helper(ans,curr,j+1,nums);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> curr;
        helper(ans,curr,0,nums);
        return ans;
    }
};
