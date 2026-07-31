class Solution {
public:
    int minimumPushes(string word) {
        vector<int> hash(26, 0);
        for (int i=0;i<word.size();i++){
            hash[word[i]-'a']++;
        }
        sort(hash.begin(),hash.end());
        reverse(hash.begin(),hash.end());
        int totalPushes = 0;
        for (int i = 0; i < 26; ++i) {
            if (hash[i] == 0) break;
            totalPushes += (i / 8 + 1) * hash[i];
        }
        return totalPushes;
    }
};
