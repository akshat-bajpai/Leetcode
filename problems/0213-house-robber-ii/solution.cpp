class Solution {
public:
    int robHelper(vector<int>& nums) {
        int n=nums.size();
        if (n==0) return 0;
        vector<int> dp(n);
        //dp[i]=max profit robbing houses till index i
        dp[0]=nums[0];
        if (n==1) return dp[0];
        dp[1]=max(nums[1],nums[0]);
        for (int i=2;i<n;i++){
            int take=dp[i-2]+nums[i];
            int notTake=dp[i-1];
            dp[i]=max(take,notTake);
        }
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        if (nums.size()==1) return nums[0];
        vector<int> left(nums.begin(),nums.end()-1);
        vector<int> right(nums.begin()+1,nums.end());
        return max(robHelper(left),robHelper(right));
    }
};
