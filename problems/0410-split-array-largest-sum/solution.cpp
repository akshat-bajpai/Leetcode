class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int low=nums[0];
        int high=0;
        for (int i=0;i<nums.size();i++){
            low=max(low,nums[i]);
            high+=nums[i];
        }
        while (low<=high){
            int mid=low+(high-low)/2;
            int tot=1;
            int curr=0;
            for (int i=0;i<nums.size();i++){
                if (curr+nums[i]>mid){
                    curr=nums[i];
                    tot++;
                }else{
                    curr+=nums[i];
                }
            }
            if (tot<=k){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};
