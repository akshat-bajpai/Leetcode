class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        int n=nums.size();
        vector<int> answer;
        for (int i=n-1;i>=0;i--){
            int num=nums[i];
            while (num){
                answer.push_back(num%10);
                num/=10;
            }
        }
        reverse(answer.begin(),answer.end());
        return answer;
    }
};
