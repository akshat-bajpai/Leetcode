class Solution {
public:
    bool isPalindrome(int y) {
        int x=y;
        int max=INT_MAX;
        int min=INT_MIN;
        int num=0;
        while (x!=0){
            if (num>max/10 || num<min/10) return 0;
            num=num*10+x%10;
            x=x/10;
        }
        if (num<0) return false;
        else{
            if (num==y){
                return true;
            }else{
                return false;
            }
        }
    }
};
