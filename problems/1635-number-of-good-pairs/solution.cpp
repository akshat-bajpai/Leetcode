class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for (int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        int num=0;
        for (auto it : mpp){
            int n=it.second;
            num+=(n*(n-1))/2;
        }
        return num;
    }
};
