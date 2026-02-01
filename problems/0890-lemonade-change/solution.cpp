class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives=0;
        int tens=0;
        int twenties=0;

        for (int i=0;i<bills.size();i++){
            if (bills[i]==5){
                fives++;
            }else if (bills[i]==10){
                fives--;
                tens++;
            }else if (bills[i]==20){
                if (tens!=0){
                    tens--;
                    fives--;
                }else{
                    fives--;
                    fives--;
                    fives--;
                }
                
                twenties++;
            }
            if (fives<0 || tens<0) return false;

        }
        return true;
    }
};
