class Solution {
public:
    bool helper(vector<int>& nums, int sum){
        int n=nums.size();
        vector<bool> prev(sum+1,false);
        prev[0]=true;
        if (nums[0]<=sum) prev[nums[0]]=true;

        for (int i=1;i<n;i++){
            vector<bool> curi(sum+1,false);
            for (int j=1;j<=sum;j++){
                bool notTake=prev[j];
                bool take=false;
                if (j-nums[i]>=0) take=prev[j-nums[i]];
                curi[j]=take || notTake;
            }
            prev=curi;
        }
        return prev[sum];
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for (int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if (sum%2==1) return false;
        return helper(nums,sum/2);
    }
};
