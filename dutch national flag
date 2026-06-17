class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        //0-low-1 : 0
        //low-mid-1 : 1
        //mid-high : 0/1/2
        //high+1 - n-1 : 2
        int low=0,mid=0,high=n-1;
        while (mid<=high){
            if (nums[mid]==0){
                swap(nums[mid],nums[low]);
                low++;mid++;
            }else if (nums[mid]==1){
                mid++;
            }else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }
        
    }
};
