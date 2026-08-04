class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        int mini=nums[0];
        int maxi=nums[0];
        for (int i=0;i<nums.size();i++){
            mini=min(mini,nums[i]);
            maxi=max(maxi,nums[i]);
        }
        set<int> st(nums.begin(),nums.end());
        for (int i=mini;i<=maxi;i++){
            if (st.find(i)==st.end()){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
