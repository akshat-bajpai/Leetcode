class Solution {
public:
    int ans(vector<int>& nums,int divisor){
        int sum=0;
        for (int i=0;i<nums.size();i++){
            sum+=ceil((double)nums[i]/divisor);
        }
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int high=INT_MIN;
        for (int i=0;i<nums.size();i++){
            high=max(high,nums[i]);
        }
        int low=1;
        int answ=0;
        while (low<=high){
            int mid=low+(high-low)/2;
            int x=ans(nums,mid);
            if (x<=threshold){
                answ=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return answ;
    }
};
