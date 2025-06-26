class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for (int i=0;i<nums.size();i++){
            if (i!=0 && nums[i-1]==nums[i]) continue;
            for (int j=i+1;j<nums.size();j++){
                if (j!=i+1 && nums[j-1]==nums[j]) continue;
                long long req=target;
                req-=nums[i];
                req-=nums[j];
                int k=j+1;
                int l=nums.size()-1;
                while (k<l){
                    long long sum=nums[k]+nums[l];
                    if (sum<req){
                        k++;
                    }
                    else if (sum>req){
                        l--;
                    }
                    else{
                        vector<int> tempAns={nums[i],nums[j],nums[k],nums[l]};
                        ans.push_back(tempAns);
                        int current_k = nums[k];
                        int current_l = nums[l];
                        k++;
                        l--;
                        while (k < l && nums[k] == current_k) k++;
                        while (k < l && nums[l] == current_l) l--;
                    }
                    
                }
            }
        }
        return ans;
    }
};
