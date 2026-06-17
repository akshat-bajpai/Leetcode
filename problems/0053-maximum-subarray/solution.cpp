class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int startIndex,start,endIndex;
        int sum=0;
        int maxSum=INT_MIN;
        for (int i=0;i<nums.size();i++){
            if (sum == 0){
                start = i;
            }
            sum += nums[i];
            if (sum > maxSum){
                maxSum = sum;
                startIndex = start;
                endIndex = i;
            }

            if (sum < 0){
                sum = 0;
            }
        }
        return maxSum;
    }
};
