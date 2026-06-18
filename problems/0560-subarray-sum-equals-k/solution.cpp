class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> prefixsum_count;
        prefixsum_count[0]=1;
        int sum=0;
        int count=0;
        for (int i=0;i<nums.size();i++){
            sum+=nums[i];
            if (prefixsum_count.find(sum-k)!=prefixsum_count.end()){
                count+=prefixsum_count[sum-k];
            }
            prefixsum_count[sum]++;
        }
        return count;
    }
};
