class Solution {
public:
    int minElement(vector<int>& nums) {
        int mini=INT_MAX;
        for (int i=0;i<nums.size();i++){
            int number=nums[i];
            int digisum=0;
            while (number){
                digisum+=(number)%10;
                number/=10;
            }
            mini=min(digisum,mini);
        }
        return mini;
    }
};
