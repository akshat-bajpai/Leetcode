class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int el1=INT_MIN;
        int cnt1=0;
        int el2=INT_MIN;
        int cnt2=0;
        vector<int> ans;

        for (int i=0;i<nums.size();i++){
            if (cnt1==0 && nums[i]!=el2){
                cnt1++;
                el1=nums[i];
            }else  if(cnt2==0 && nums[i]!=el1){
                cnt2++;
                el2=nums[i];
            }else if(nums[i]==el1) cnt1++;
            else if (nums[i]==el2) cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }
        int c1=0;
        int c2=0;
        for (int i=0;i<nums.size();i++){
            if (nums[i]==el1) c1++;
            if (nums[i]==el2) c2++;
        }
        if (c1>nums.size()/3) ans.push_back(el1);
        if (c2>nums.size()/3) ans.push_back(el2);
        return ans;
    }
};
