class Solution {
public:
    int romanToInt(string s) {
        int num=0;
        map<char,int>mpp;
        mpp['I']=1;mpp['V']=5;mpp['X']=10;mpp['L']=50;mpp['C']=100;mpp['D']=500;mpp['M']=1000;

        for (int i=0;i<s.size();i++){
            if (i<s.size()-1){
                if (s[i]=='I' && (s[i+1]=='V' || s[i+1]=='X')){
                    num=num-1;continue;
                }
                else if (s[i]=='X' && (s[i+1]=='L' || s[i+1]=='C')){
                    num=num-10;continue;
                }
                else if (s[i]=='C' && (s[i+1]=='D' || s[i+1]=='M')){
                    num=num-100;continue;
                }
            }
            num=num+mpp[s[i]];
        }
        return num;
    }
};
