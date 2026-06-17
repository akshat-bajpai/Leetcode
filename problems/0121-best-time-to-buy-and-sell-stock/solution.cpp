class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int maxProfit=0;
        int mini=INT_MAX;
        for (int i=0;i<nums.size();i++){
            if (mini==INT_MAX) mini=nums[i];
            if (nums[i]<mini){
                mini=nums[i];
                continue;
            }
            if (nums[i]-mini>maxProfit){
                maxProfit=nums[i]-mini;
            }
        }
        return maxProfit;
    }
};
