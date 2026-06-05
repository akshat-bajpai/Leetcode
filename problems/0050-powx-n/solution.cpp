class Solution {
public:
    double myPow(double x, long long n) {
        if (n<0){
            x=1/x;
            return myPow(x,-1*n);
        }
        if (n==0) return 1;
        double half=myPow(x,n/2);
        double calculation=half*half;
        if (n%2==1){
            calculation*=x;
        }
        return calculation;
    }
};
