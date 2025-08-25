class Solution {
public:
    int maxDepth(string s) {
        int c=0;
        int maxi=0;

        for (int i=0;i<s.size();i++){
            if (s[i]=='('){
                c++;
                maxi=max(maxi,c);
            }else if (s[i]==')'){
                c--;
            }
            
        }
        return maxi;
    }
};
