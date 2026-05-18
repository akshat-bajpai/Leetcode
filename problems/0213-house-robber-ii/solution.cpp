class Solution {
public:
    int rob(vector<int>& nums) {
        //case 1: we dont take n-1th and take 0th
        int prev2=0;
        int prev=nums[0];
        int curi=nums[0];
        for (int i=1;i<nums.size()-1;i++){
            int take=prev2+nums[i];
            int notTake=prev;
            curi=max(take,notTake);
            prev2=prev;
            prev=curi;
        }

        int case1=curi;
        //case 1 dont take 0th

        prev2=0;
        if (nums.size()==1) return nums[0];
        prev=nums[1];
        curi=prev;
        for (int i=2;i<nums.size();i++){
            int take=prev2+nums[i];
            int notTake=prev;
            curi=max(take,notTake);
            prev2=prev;
            prev=curi;
        }

        int case2=curi;

        return max(case1, case2);
    }
};
