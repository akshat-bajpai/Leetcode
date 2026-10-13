class Solution {
public:
    static bool comp(int a, int b){
        return abs(a)>abs(b);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end(),comp);
        long long maxSum=0;
        for (int i=0;i<n;i++){
            if (i<(n+1)/2){
                maxSum+=(nums[i]*nums[i]);
            }else{
                maxSum-=(nums[i]*nums[i]);
            }
        }
        return maxSum;
    }
};
