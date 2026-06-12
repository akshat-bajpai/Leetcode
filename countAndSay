class Solution {
public:
    string countAndSay(int n) {
        if (n==1) return "1";
        string s=countAndSay(n-1);
        int i=0;
        string ans="";
        while (i<s.size()){
            int j=i;
            int freq=0;
            while (j<s.size() && s[j]==s[i]){
                freq++;
                j++;
            }
            ans+=to_string(freq)+s[i];
            i=j;
        }
        return ans;
    }
};
