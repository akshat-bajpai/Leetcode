class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int sum=0;
        for (int i=0;i<n;i++){
            sum+=nums[i];
        }
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2)));
        for (int i = 0; i < n; i++) {
            dp[i][i][0] = nums[i];
            dp[i][i][1] = 0;
        }
        for (int i =n-1;i>=0;i--) {
            for (int j=i+1;j<n;j++) {
                dp[i][j][0] = max(nums[i] + dp[i + 1][j][1], nums[j] + dp[i][j - 1][1]);
                dp[i][j][1] = min(dp[i + 1][j][0],dp[i][j - 1][0]);
            }
        }
        return dp[0][n - 1][0] >= sum - dp[0][n - 1][0];
    }
};
