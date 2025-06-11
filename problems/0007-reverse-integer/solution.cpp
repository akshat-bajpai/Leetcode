class Solution {
public:
    int reverse(int x) {
        int rev=0;
        int x_sign=x;
        if (x==-(pow(2,31))){
            return 0;
        }
        if (x_sign<0){
            x=x*(-1);
        }

        while (x>0){
            int digit=x%10;
            x=x/10;
            if (rev > INT_MAX/10 || (rev == INT_MAX/10 && digit > 7)) return 0;
            if (rev < INT_MIN/10 || (rev == INT_MIN/10 && digit < -8)) return 0;
            rev=rev*10+digit;
        }
        if (x_sign<0){
            return rev*(-1);
        }
        return rev;
    }
};
