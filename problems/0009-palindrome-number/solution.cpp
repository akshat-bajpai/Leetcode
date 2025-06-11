class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0){
            return false;
        }
        int dup=x;
        int rev=0;
        while (dup>0){
            int digit=dup%10;
            if (rev > INT_MAX/10 || (rev == INT_MAX/10 && digit > 7)) return 0;
            if (rev < INT_MIN/10 || (rev == INT_MIN/10 && digit < -8)) return 0;
            rev=rev*10+digit;
            dup=dup/10;
        }
        if (rev==x){
            return true;
        }else{ return false;}
    }
};
