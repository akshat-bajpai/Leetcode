class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n=nums.size();
        int maxi=0;
        unordered_map<int,int> mpp;
        for (int i=0;i<n;i++){
            mpp[nums[i]]++;
            maxi=max(maxi,mpp[nums[i]]);
        }
        vector<vector<int>> ans(maxi);
        for (auto it : mpp){
            int num=it.first;
            int freq=it.second;
            for (int i=0;i<freq;i++){
                ans[i].push_back(num);
            }
        }
        return ans;
    }
};
