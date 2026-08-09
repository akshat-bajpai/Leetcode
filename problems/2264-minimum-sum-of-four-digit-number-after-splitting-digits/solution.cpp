class Solution {
public:
    int minimumSum(int num) {
        vector<int> digits;
        for (int i=0;i<4;i++){
            digits.push_back(num%10);
            num=num/10;
        }
        sort(digits.begin(),digits.end());
        return 10*digits[0]+10*digits[1]+digits[2]+digits[3];
    }
};
