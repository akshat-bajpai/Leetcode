class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans;
        for (int i=0;i<words.size();i++){
            string word=words[i];
            int sum=0;
            for (int j=0;j<word.size();j++){
                sum+=weights[word[j]-'a'];
            }
            sum=sum%26;
            ans+='z'-sum;
        }
        return ans;
    }
};
