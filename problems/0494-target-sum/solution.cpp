class Solution {
public:
    int helper(vector<int>& arr, int target){
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(target+1,0));
        //dp[i][j]=number of subsets forming sum j till index i
        if (arr[0]==0) dp[0][0]=2;
        else{
            dp[0][0]=1;
            if (arr[0]<=target) dp[0][arr[0]]=1;
        }
        for (int i=1;i<n;i++){
            for (int j=0;j<=target;j++){
                int notTake=dp[i-1][j];
                int take=0;
                if (j-arr[i]>=0) take=dp[i-1][j-arr[i]];
                dp[i][j]=take+notTake;
            }
        }
        return dp[n-1][target];
    }


    int findTargetSumWays(vector<int>& nums, int target) {
        // s1-s2=target
        // s1+s2=sum
        // s1=(target+sum)/2
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }        
        if ((target+sum)%2==1 || target+sum<0) return 0;
        target=(target+sum)/2;
        return helper(nums,target);
    }
};
