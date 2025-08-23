class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size()!=t.size()) return false;
        map<int,int> mpp;
        for (int i=0;i<s.size();i++){
            mpp[s[i]]++;
        }
        map<int,int> mpp1;
        for (int i=0;i<t.size();i++){
            mpp1[t[i]]++;
        }

        for (auto it : mpp){
            if (it.second==mpp1[it.first]){}
            else return false;
        }
        return true;
    }
};
