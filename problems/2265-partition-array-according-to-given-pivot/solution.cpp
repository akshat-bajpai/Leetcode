class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> before;
        vector<int> dur;
        vector<int> after;
        for (int i=0;i<nums.size();i++){
            if (nums[i]<pivot) before.push_back(nums[i]);
            else if (nums[i]==pivot) dur.push_back(nums[i]);
            else after.push_back(nums[i]);
        }
        for (int i=0;i<before.size();i++){
            nums[i]=before[i];
        }
        for (int i=0;i<dur.size();i++){
            nums[i+before.size()]=dur[i];
        }
        for (int i=0;i<after.size();i++){
            nums[i+before.size()+dur.size()]=after[i];
        }
        return nums;
    }
};
