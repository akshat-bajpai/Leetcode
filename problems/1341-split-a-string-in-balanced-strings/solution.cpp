class Solution {
public:
    int balancedStringSplit(string s) {
        int n=s.size();
        int bal=0;
        int tot=0;
        for (int i=0;i<n;i++){
            if (s[i]=='L') bal++;
            else bal--;
            if (bal==0) tot++;
        }
        return tot;
    }
};
