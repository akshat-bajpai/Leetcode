class Solution {
public:
    int helper(vector<int>& nums, int curxor, int index){
        if (index==nums.size()) return curxor;
        int take=helper(nums,curxor^nums[index],index+1);
        int notTake=helper(nums,curxor,index+1);
        return take+notTake;
    }
    int subsetXORSum(vector<int>& nums) {
        return helper(nums,0,0);
    }
};
