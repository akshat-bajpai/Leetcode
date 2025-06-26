class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            int j=i+1;
            int k=nums.size()-1;
            int req=0-nums[i];
            if (i!=0 && nums[i-1]==nums[i]) continue;

            while (j<k){
                if (nums[j]+nums[k]<req){
                    j++;
                }
                else if(nums[k]+nums[j]>req){
                    k--;
                }
                else if (nums[j]+nums[k]==req){
                    vector<int> tempAns;
                    tempAns={nums[i],nums[j],nums[k]};
                    ans.push_back(tempAns);
                    j++;
                    k--;
                    while (j<k && nums[j-1]==nums[j] ) j++;
                    while (j<k && nums[k+1]==nums[k] ) k--;
                }
            }
        }
        return ans;
    }
};
