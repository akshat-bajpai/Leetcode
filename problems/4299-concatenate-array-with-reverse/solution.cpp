class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        int n=nums.size();
        vector<int> newArr=nums;
        reverse(newArr.begin(),newArr.end());
        vector<int> ans(2*n);
        for (int i=0;i<n;i++){
            ans[i]=nums[i];
        }
        for (int i=0;i<n;i++){
            ans[i+n]=newArr[i];
        }
        return ans;
    }
};
