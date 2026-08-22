class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for (int i=n-1;i>=0;i--){
            for (int j=-1;j<n;j++){
                int notTake=dp[i+1][j+1];
                int take=0;
                if (j==-1 || nums[j]<nums[i] ) take=dp[i+1][i+1]+1;
                dp[i][j+1]=max(take,notTake);
            }
        }
        return dp[0][0];
    }
};
