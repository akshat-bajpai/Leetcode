class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0;
        unordered_map<char,int> mpp;
        int maxi=0;
        int c=0;
        for (int j=0;j<s.size();j++){
            if (mpp.find(s[j])==mpp.end()){
                mpp[s[j]]=1;
                c++;
                maxi=max(maxi,c);
            }
            else{
                while (mpp.find(s[j])!=mpp.end()){
                    mpp.erase(s[i]);
                    i++;
                    c--;
                }
                mpp[s[j]]=1;
                c++;
            }
        }
        return maxi;
    }
};
