class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>st;
        vector<int> dp(nums.size(),1);
        dp[0]=1;
        vector<int> hash(nums.size(),0);
        int largest=1;
        int largestIndex=0;
        for (int i=1;i<nums.size();i++){
            hash[i]=i;
            for (int j=0;j<i;j++){
                if (nums[i]%nums[j]==0 ) {
                    if (dp[j]+1>dp[i]){
                        dp[i]=dp[j]+1;
                        hash[i]=j;
                    }
                }
            }
            if (dp[i]>largest){
                largest=dp[i];
                largestIndex=i;
            }
        }
        while (hash[largestIndex]!=largestIndex){
            st.push_back(nums[largestIndex]);
            largestIndex=hash[largestIndex];
        }
        st.push_back(nums[largestIndex]);
        return st;
    }
};
