class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ind=0;
        nums[ind]=nums[0];
        ind++;
        for (int i=1;i<nums.size();i++){
            if (nums[i]==nums[ind-1]){
                continue;
            }
            nums[ind]=nums[i];
            ind++;
        }
        return ind;
    }
};
