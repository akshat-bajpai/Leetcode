class Solution {
public:
    int minAddToMakeValid(string s) {
        int c=0;
        int l=0;
        int n=s.size();
        for (int i=0;i<n;i++){
            if (s[i]=='(') c++;
            else if (s[i]==')') {
                c--;
                if (c<0) {
                    l++;
                    c=0;
                }
            }
        }
        
        return c+l;
    }
};
