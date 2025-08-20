class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int minLen=strs[0].size();
        string ans="";
        for (int i=0;i<strs.size();i++){
            minLen=min((int)strs[i].size(),minLen);
        }

        for (int i=0;i<minLen;i++){
            char c=strs[0][i];
            for (int j=0;j<strs.size();j++){
                if (strs[j][i]==c){}
                else return ans;
            }
            ans+=c;
        }
        return ans;
    }
};
