class Solution {
public:
    int countDigits(int num) {
        int ans=0;
        int temp=num;
        while (temp){
            if (num%(temp%10)==0) ans++;
            temp=temp/10;
        }
        return ans;
    }
};
