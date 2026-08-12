class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        if (k<=0) return 0;
        unordered_map<int,int> mpp;
        int l=0;
        int maxlen=0;
        for (int i=0;i<nums.size();i++){
            if (mpp[nums[i]]>=k){
                while (mpp[nums[i]]>=k){
                    mpp[nums[l]]--;
                    l++;
                }
            }
            mpp[nums[i]]++;
            maxlen=max(maxlen,i-l+1);
        }
        return maxlen;
    }
};
