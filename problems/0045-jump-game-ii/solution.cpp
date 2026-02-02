class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps=0;
        int maxi=0;
        int curr=0;

        for (int i=0;i<nums.size()-1;i++){
            maxi=max(i+nums[i],maxi);

            if (i==curr){
                curr=maxi;
                jumps++;
            }
        }
        return jumps;
    }
};
