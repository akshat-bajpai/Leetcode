class Solution {
public:
    int numberOfMatches(int n) {
        int total=0;
        while (n){
            if (n%2==0){
                total+=n/2;
                n=n/2;
            }else{
                if (n==1) break;
                total+=(n-1)/2;
                n=(n-1)/2+1;
            }
        }
        return total;
    }
};
