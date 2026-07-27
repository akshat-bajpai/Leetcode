class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int num=0;
        unordered_set<char>st(allowed.begin(),allowed.end());
        for (int i=0;i<words.size();i++){
            string word = words[i];
            bool consistent=true;
            for (int j=0;j<word.size();j++){
                if (st.find(word[j])==st.end()){
                    consistent=false;
                }
            }
            if (consistent) num++;
        }
        return num;

    }
};
