class Solution {
public:
    int mod_merge(vector<int>& nums, int low, int mid, int high){
        vector<int> temp(high-low+1);
        int j=mid+1;
        int cnt=0;
        for (int i=low;i<=mid;i++){
            while (j<=high && nums[i]>2LL*nums[j]){
                j++;
            }
            cnt+=j-(mid+1);
        }
        int i=low;j=mid+1;
        int ind=0;

        while (i<=mid && j<=high){
            if (nums[i]<=nums[j]){
                temp[ind]=nums[i];
                ind++;i++;
            }else{
                temp[ind]=nums[j];
                ind++;j++;
            }
        }
        while (i<=mid){
            temp[ind]=nums[i];
            ind++;i++;
        }
        while(j<=high){
            temp[ind]=nums[j];
            ind++;j++;
        }
        for (int k=low;k<=high;k++){
            nums[k]=temp[k-low];
        }
        return cnt;
    }
    int mod_merge_sort(vector<int>& nums, int low, int high){
        if (low>=high){
            return 0;
        }
        int mid=low+(high-low)/2;
        int l=mod_merge_sort(nums,low,mid);
        int r=mod_merge_sort(nums,mid+1,high);
        int c=mod_merge(nums,low,mid,high);

        return l+r+c;
    }
    int reversePairs(vector<int>& nums) {
        return mod_merge_sort(nums,0,nums.size()-1);
    }
};
