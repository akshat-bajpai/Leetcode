class Solution {
public:
    bool checkDivisibility(int n) {
        int number=n;
        int digiSum=0;
        int digiProd=1;
        while (n){
            int digi=n%10;
            n/=10;
            digiSum+=digi;
            digiProd*=digi;
        }
        int sum=digiSum+digiProd;
        return (number%sum==0);
    }
};
