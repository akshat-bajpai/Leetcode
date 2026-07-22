class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());
        int p=0;
        int c=0;
        for (int i=0;i<g.size();i++){
            if (p>=s.size()) break;
            if (s[p]>=g[i]){
                c++;p++;
            }else{
                while (p<s.size() && s[p]<g[i]){
                    p++;
                }
                if (p==s.size()) break;
                c++;
                p++;
            }
        }
        return c;
    }
};
