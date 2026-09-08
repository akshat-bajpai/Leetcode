class Solution {
public:
    int countCommas(int n) {
        //4 digit :1, 5 digit: 1
        if (n>999) return n-1000+1;
        return 0;
    }
};
