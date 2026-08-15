class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        int x=0;
        bool allZeroes=true;
        for (int i=0;i<n;i++){
            if (nums[i]!=0) allZeroes=false;
            x=x^nums[i];
        }
        if (allZeroes) return 0;
        if (x==0) return n-1;
        return n;
    }
};
