class Solution {
public:
    int helper(string& s, int i, long long num, int sign){
        if (i>s.size() || isdigit(s[i])==false) return num;
        num=10*num+(sign)*(s[i]-'0');
        if (num<INT_MIN) return INT_MIN;
        if (num>INT_MAX) return INT_MAX;
        return helper(s,i+1,num,sign);
    }
    int myAtoi(string s) {
        int i=0;
        int n=s.size();
        while (i<s.size() && s[i]==' '){
            i++;
        }
        int sign=1;
        if (s[i]=='-' || s[i]=='+'){
            sign= (s[i]=='-') ? -1 : 1;
            i++;
        }

        return helper(s,i,0,sign);
    }
};
