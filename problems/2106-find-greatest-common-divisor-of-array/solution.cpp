class Solution {
public:
    int findGCD(vector<int>& nums) {
        int lowest=nums[0];
        int highest=nums[0];
        for (int i=0;i<nums.size();i++){
            lowest=min(lowest,nums[i]);
            highest=max(highest,nums[i]);
        }
        int gcd=1;
        for (int i=1;i<=lowest;i++){
            if (highest%i==0 && lowest%i==0) gcd=i;
        }
        return gcd;
    }
};
