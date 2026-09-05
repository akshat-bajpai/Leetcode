class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> prefMax(n);
        vector<int> suffMin(n);
        for (int i=0;i<n;i++){
            if (i==0){
                prefMax[i]=nums[i];
                suffMin[n-1-i]=nums[n-1-i];
                continue;
            }
            prefMax[i]=max(prefMax[i-1],nums[i]);
            suffMin[n-1-i]=min(suffMin[n-i],nums[n-i-1]);
        }
        for (int i=0;i<n;i++){
            if (prefMax[i]-suffMin[i]<=k) return i;
        }
        return -1;
    }
};
