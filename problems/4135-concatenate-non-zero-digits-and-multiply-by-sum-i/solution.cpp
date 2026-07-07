class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum=0;
        long long x=0;
        string s=to_string(n);
        string res="";
        for (int i=0;i<s.size();i++){
            if (s[i]!='0'){
                res+=s[i];
                sum+=s[i]-'0';
            }
        }
        if (res=="") return 0;
        x=stoll(res);
        return x*sum;
    }
};
