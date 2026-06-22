class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curMax=1;
        int curMin=1;
        int ans=INT_MIN;
        for (int i=0;i<nums.size();i++){
            int temp=curMax*nums[i];
            curMax=max(curMax*nums[i],max(curMin*nums[i],nums[i]));
            curMin=min(temp,min(curMin*nums[i],nums[i]));
            ans=max(ans,curMax);
        }
        return ans;
    }
};
