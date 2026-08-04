class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int occurences=0;
        for (int i=0;i<nums.size();i++){
            int num=nums[i];
            while (num){
                int d=num%10;
                if (d==digit) occurences++;
                num=num/10;
            }
        }
        return occurences;
    }
};
