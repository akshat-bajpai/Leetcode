class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        //case 1: take 0 house not take n-1 house
        //case 2 not take 0 house

        vector<int> dp(n,0);
        dp[0]=0; //not take;
        for (int i=1;i<n;i++){
            int take=nums[i]+(i==1?0:dp[i-2]);
            int notTake=dp[i-1];
            dp[i]=max(take,notTake);
        }

        vector<int> dp2(n,0);
        dp2[0]=nums[0];
        for (int i=1;i<n-1;i++){
            int take=nums[i] + (i==1?0:dp2[i-2]);
            int notTake=dp2[i-1];
            dp2[i]=max(take,notTake);
        }
        if (n==1) return nums[0];
        return max(dp[n-1],dp2[n-2]);
    }
};
