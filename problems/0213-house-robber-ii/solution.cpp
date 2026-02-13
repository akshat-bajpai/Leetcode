class Solution {
public:
    int rob(vector<int>& nums) {
        int prev=nums[0];
        int prev2=0;
        for (int i=1;i<nums.size()-1;i++){
            int take=nums[i]+prev2;
            int notTake=prev;
            int curi=max(take,notTake);
            prev2=prev;
            prev=curi;;
        }
        int case1= prev;
        if (nums.size()>=2)prev=nums[1];
        else return nums[0];
        prev2=0;
        for (int i=2;i<nums.size();i++){
            int take=nums[i]+prev2;
            int notTake=prev;
            int curi=max(take,notTake);
            prev2=prev;
            prev=curi;;
        }
        int case2= prev;

        return max(case1,case2);
    }
};
