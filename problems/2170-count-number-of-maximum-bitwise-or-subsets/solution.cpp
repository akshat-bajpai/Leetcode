class Solution {
public:
    int helper(vector<int>& nums, int idx, int x, int targetOr){
        if (nums.size()==idx){
            if (x==targetOr) return 1;
            return 0;
        }
        int l=helper(nums,idx+1,x|nums[idx],targetOr);
        int r=helper(nums,idx+1,x,targetOr);
        return l+r;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr=0;
        for (int i=0;i<nums.size();i++){
            maxOr=maxOr|nums[i];
        }
        return helper(nums,0,0,maxOr);
    }
};
