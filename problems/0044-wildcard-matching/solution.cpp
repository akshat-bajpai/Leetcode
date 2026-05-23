class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<bool> prev(m+1),cur(m+1);

        for (int i=1;i<=n;i++){
            prev[0]=false;
        }
        prev[0]=true;
        bool flag=false;
        for (int i=1;i<=m;i++){
            if (p[i-1]!='*'){
                flag=true;
            }
            if (!flag) prev[i]=true;
            else prev[i]=false;
        }
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                if (s[i-1]==p[j-1]){
                    cur[j]=prev[j-1];
                }else if (p[j-1]=='?'){
                    cur[j]=prev[j-1];
                }else if (p[j-1]=='*'){
                    cur[j]=prev[j] || cur[j-1];
                }else{
                    cur[j]=false;
                }
            }
            prev=cur;
        }
        return prev[m];
    }
};
