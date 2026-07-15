class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int oddSum=n*n;
        int evenSum=n*(n+1);
        int gcd=1;
        for (int i=1;i<=oddSum;i++){
            if (oddSum%i==0 && evenSum%i==0) gcd=i;
        }
        return gcd;
    }
};
