class Solution {
public:
    int helper(vector<int>& nums, int target){
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(target+1,0)); //number of ways to make j using coins till index i
        if (nums[0]==0){
            dp[0][0]=2;
        }else{
            dp[0][0]=1;
            if (nums[0]<=target) dp[0][nums[0]]=1;
        }
        for (int i=1;i<n;i++){
            for (int j=0;j<=target;j++){
                int notTake=dp[i-1][j];
                int take=0;
                if (j-nums[i]>=0) take=dp[i-1][j-nums[i]];
                dp[i][j]=notTake+take;
            }
        }
        return dp[n-1][target];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for (int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if ((sum+target)%2==1) return 0;
        if (sum+target<0) return 0;
        return helper(nums,(sum+target)/2);
    }
};
