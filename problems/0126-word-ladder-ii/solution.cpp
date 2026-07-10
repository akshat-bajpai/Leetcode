class Solution {
public:
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> parent;

    void dfs(string word, string beginWord, vector<string>& path) {
        if (word == beginWord) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            return;
        }

        for (auto &par : parent[word]) {
            path.push_back(par);
            dfs(par, beginWord, path);
            path.pop_back();
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord,
                                       vector<string>& wordList) {

        unordered_set<string> dict(wordList.begin(), wordList.end());

        if (!dict.count(endWord))
            return {};

        unordered_set<string> currentLevel;
        currentLevel.insert(beginWord);

        bool found = false;

        while (!currentLevel.empty() && !found) {

            for (auto &w : currentLevel)
                dict.erase(w);

            unordered_set<string> nextLevel;

            for (auto word : currentLevel) {

                string original = word;

                for (int i = 0; i < word.size(); i++) {

                    char old = word[i];

                    for (char c = 'a'; c <= 'z'; c++) {

                        word[i] = c;

                        if (!dict.count(word))
                            continue;

                        nextLevel.insert(word);
                        parent[word].push_back(original);

                        if (word == endWord)
                            found = true;
                    }

                    word[i] = old;
                }
            }

            currentLevel = nextLevel;
        }

        if (!found)
            return {};

        vector<string> path = {endWord};
        dfs(endWord, beginWord, path);

        return ans;
    }
};
