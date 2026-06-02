class Solution {
public:
    const int mod=1e9+7;

    long long findPow(long long a, long long b){
        if (b==0) return 1;
        long long calc=findPow(a,b/2);
        long long result=(calc*calc)%mod;
        if (b%2==1){
            result=(result*a)%mod;
        }
        return result;
    }
    int countGoodNumbers(long long n) {
        long long odds=(n/2);
        long long evens=(n+1)/2;
        long long ans=(findPow(4,odds)*findPow(5,evens))%mod;
        return ans;
    }
};
