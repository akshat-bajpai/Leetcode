class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives=0,tens=0,twenties=0;

        for (int i=0;i<bills.size();i++){
            if (bills[i]==5){
                fives++;
            }else if (bills[i]==10){
                if (fives==0) return false;
                tens++;
                fives--;
            }else{
                int c=0;
                while (c!=15){
                    if (tens!=0 && c==0){
                        tens--;
                        c+=10;
                    }else if (fives!=0){
                        fives--;
                        c+=5;
                    }else{
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
