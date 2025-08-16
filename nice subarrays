class Solution {
public:

    int helper(vector<int>& nums,int k){
        if (k<0) return 0;
        int l=0;
        int r=0;
        int n=0;
        int count=0;

        while(r<nums.size()){
            if (nums[r]%2==1) n++;

            while(n>k){
                if (nums[l]%2==1) n--;
                l++;
            }

            count+=r-l+1;
            r++;
        }
        return count;
    }


    int numberOfSubarrays(vector<int>& nums, int k) {
        return helper(nums,k)-helper(nums,k-1);
    }
};
