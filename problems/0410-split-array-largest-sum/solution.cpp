class Solution {
public:
    int ways(vector<int>& nums, int maxi){
        int way=1;
        int c=0;
        for (int i=0;i<nums.size();i++){
            if (c+nums[i]<=maxi){
                c+=nums[i];
            }else{
                way++;
                c=nums[i];
            }
        }
        return way;
    }


    int splitArray(vector<int>& nums, int k) {
        int low=INT_MIN;
        int high=0;
        for (int i=0;i<nums.size();i++){
            low=max(low,nums[i]);
            high+=nums[i];
        }

        while (low<=high){
            int mid=low+(high-low)/2;
            if (ways(nums,mid)>k){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return low;
    }
};
