class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n+1,0);
        for (int i=n-1;i>=0;i--){
            int len=0;
            int maxi=-1e9;
            int ans=-1e9;
            for (int j=i;j<min(i+k,n);j++){
                len++;
                maxi=max(maxi,arr[j]);
                ans=max(ans,maxi*len+dp[j+1]);
            }
            dp[i]=ans;
        }
        return dp[0];
    }
};
