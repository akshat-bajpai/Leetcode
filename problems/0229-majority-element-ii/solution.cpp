class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int el1=INT_MIN;
        int el2=INT_MIN;
        int c1=0;
        int c2=0;
        for (int i=0;i<nums.size();i++){
            if (nums[i]!=el2 && el1==INT_MIN){
                el1=nums[i];
                c1++;
                continue;
            }
            if (nums[i]!=el1 && el2==INT_MIN){
                el2=nums[i];
                c2++;
                continue;
            }

            if (nums[i]==el1){
                c1++;
            }else if(nums[i]==el2){
                c2++;
            }else{
                c1--;c2--;
            }
            if (c1==0){
                el1=INT_MIN;
            }
            if (c2==0){
                el2=INT_MIN;
            }
        }
        vector<int> ans;
        c1=0;
        c2=0;
        for (int i=0;i<nums.size();i++){
            if (nums[i]==el1) c1++;
            if (nums[i]==el2) c2++;
        }
        if (c1>nums.size()/3) ans.push_back(el1);
        if (c2>nums.size()/3) ans.push_back(el2);
        return ans;

    }
};
