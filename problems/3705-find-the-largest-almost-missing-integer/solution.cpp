class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        if (k==1){
            unordered_map<int,int>mpp;
            for (int i=0;i<n;i++){
                mpp[nums[i]]++;
            }
            int largest=-1;
            for (auto it : mpp){
                if (it.second==1) largest=max(largest,it.first);
            }
            return largest;
        }else if (k==n){
            int largest=nums[0];
            for (int i=0;i<n;i++){
                largest=max(largest,nums[i]);
            }
            return largest;
        }else{
            unordered_map<int,int>mpp;
            for (int i=0;i<n;i++){
                mpp[nums[i]]++;
            }
            if (mpp[nums[0]]==1 && mpp[nums[n-1]]==1) return max(nums[0],nums[n-1]);
            if (mpp[nums[0]]==1) return nums[0];
            if (mpp[nums[n-1]]==1) return nums[n-1];
            return -1;
        }
        return -1;
    }
};
