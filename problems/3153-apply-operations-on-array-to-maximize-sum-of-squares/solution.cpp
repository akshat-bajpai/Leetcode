class Solution {
public:
    const int MOD=1e9+7;
    int maxSum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> bitMap(32,0);
        for (int i=0;i<n;i++){
            for (int shift=0;shift<32;shift++){
                int set=(nums[i]>>shift)&1;
                bitMap[shift]+=set;
            }
        }
        long long sum=0;
        vector<long long> elements(k,0);
        for (int i=0;i<k;i++){
            for (int shift=0;shift<32;shift++){
                if (bitMap[shift]){
                    elements[i]=elements[i] | (1<<shift);
                    bitMap[shift]--;
                }
            }
        }
        for (int i=0;i<k;i++){
            sum=(sum+elements[i]*elements[i])%MOD;
        }
        return sum%MOD;
    }
};
