class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1); //dp[i]=longest lis that ends with i
        vector<int> numLis(n,1); //number of LIS that end at i
        int maxi=1;
        for (int i=0;i<n;i++){
            for (int prev=0;prev<i;prev++){
                if (nums[prev]<nums[i]){
                    if (dp[i]<dp[prev]+1){
                        dp[i]=dp[prev]+1;
                        numLis[i]=numLis[prev];
                    }else if (dp[i]==dp[prev]+1){
                        numLis[i]+=numLis[prev];
                    }
                    
                }
            }
            maxi=max(maxi,dp[i]);
        }
        int ans=0;
        for (int i=0;i<n;i++){
            if (dp[i]==maxi){
                ans+=numLis[i];
            }
        }
        return ans;
    }
};
