class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=0;
        for (int i=0;i<n;i++){
            int set=0;
            for (int bit=0;bit<32;bit++){
                if (((i>>bit)&1)==1) set++;
            }
            if (set==k) sum+=nums[i];
        }
        return sum;
    }
};
