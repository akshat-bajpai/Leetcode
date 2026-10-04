class Solution {
public:
    bool checkValidString(string s) {
        int min=0;
        int max=0;
        for (int i=0;i<s.size();i++){
            if (s[i]=='('){
                max++;
                min++;
            }else if (s[i]==')'){
                max--;
                min--;
                if (min<0) min=0;
                if (max<0) return false;
            }else{
                max++;
                min--;
                if (min<0) min=0;
            }
        }
        return min==0;
    }
};
