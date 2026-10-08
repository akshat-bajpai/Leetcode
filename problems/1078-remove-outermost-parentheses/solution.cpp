class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.size();
        string ans="";
        string temp="";
        int diff=0;
        for (int i=0;i<n;i++){
            if (s[i]=='('){
                diff++;
                temp+=s[i];
            }else{
                diff--;
                temp+=s[i];
                if (diff==0){
                    ans+=temp.substr(1,temp.size()-2);
                    temp="";
                }
            }
        }
        return ans;
    }
};
