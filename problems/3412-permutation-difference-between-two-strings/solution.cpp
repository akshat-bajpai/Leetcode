class Solution {
public:
    int findPermutationDifference(string s, string t) {
        unordered_map<int,int> mapCharToOccuranceInT;
        for (int i=0;i<t.size();i++){
            mapCharToOccuranceInT[t[i]]=i;
        }
        int ans=0;
        for (int i=0;i<s.size();i++){
            ans+=abs(i-mapCharToOccuranceInT[s[i]]);
        }
        return ans;
    }
};
