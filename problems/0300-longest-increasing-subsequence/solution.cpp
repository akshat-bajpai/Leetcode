/*
f(i,j) => longest increasing subsequence starting at index i with last chose element as index j
    if (i==n) return 0;
    take=0;
    if (nums[i]>nums[j]) take=1+f(i+1,i);
    dont take=f(i+1,j);
    return max(take,notTake)
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for (int i=n-1;i>=0;i--){
            for (int j=-1;j<i;j++){
                int take=0;
                if (j==-1 || nums[i]>nums[j]) take=1+dp[i+1][i+1];
                int donttake=dp[i+1][j+1];
                dp[i][j+1]=max(take,donttake);
            }
        }
        return dp[0][0];
    }
};
