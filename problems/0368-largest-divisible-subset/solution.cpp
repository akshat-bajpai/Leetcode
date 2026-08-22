class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int maxi=1;
        int largestIndex=0;
        vector<int> dp(n,1);
        vector<int> hash(n);
        for (int i=0;i<n;i++){
            hash[i]=i;
            for (int j=0;j<i;j++){
                if (nums[i]%nums[j]==0){
                    if (dp[i]<dp[j]+1){
                        dp[i]=dp[j]+1;
                        hash[i]=j;
                    }
                }
            }
            if (dp[i]>maxi){
                maxi=dp[i];
                largestIndex=i;
            }
        }
        vector<int> s;
        s.push_back(nums[largestIndex]);
        while (hash[largestIndex]!=largestIndex){
            largestIndex=hash[largestIndex];
            s.push_back(nums[largestIndex]);
        }
        return s;
    }
};
