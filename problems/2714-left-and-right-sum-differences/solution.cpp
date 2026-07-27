class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int> leftSum(n),rightSum(n);
        vector<int> answer(n);
        int ls=0;
        int rs=0;
        for (int i=0;i<n;i++){
            leftSum[i]=ls;
            rightSum[n-i-1]=rs;
            ls+=nums[i];
            rs+=nums[n-i-1];
        }
        for (int i=0;i<n;i++){
            answer[i]=abs(leftSum[i]-rightSum[i]);
        }
        return answer;
    }
};
