class Solution {
public:
    void helper(set<vector<int>>& st, vector<int> curr, int i, vector<int>& nums){
        if (i==nums.size()){
            st.insert(curr);
            return;
        }
        helper(st,curr,i+1,nums);
        curr.push_back(nums[i]);
        helper(st,curr,i+1,nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>> st;
        helper(st,{},0,nums);
        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
    }
};
