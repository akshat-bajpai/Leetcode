class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for (int i=0;i<n-2;i++){
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int l=i+1,r=n-1;
            int target=-nums[i];
            while (l<r){
                if (nums[l]+nums[r]==target){
                    ans.push_back({nums[i],nums[l],nums[r]});
                    l++;
                    while (l<r && nums[l]==nums[l-1]) l++;
                }else if (nums[l]+nums[r]<target){
                    l++;
                    while (l<r && nums[l]==nums[l-1]) l++;
                }else{
                    r--;
                    while (l<r && nums[r]==nums[r+1]) r--;
                }
            }
        }
        return ans;
    }
};
