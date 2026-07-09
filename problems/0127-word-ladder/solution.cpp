class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> st(wordList.begin(),wordList.end());
        queue<string> q;
        q.push(beginWord);
        int len=1;
        while (!q.empty()){
            int s=q.size();
            for (int i=0;i<s;i++){
                string front=q.front();
                q.pop();
                string ogWord=front;
                if (ogWord==endWord) return len;
                string word=ogWord;
                for (int j=0;j<word.size();j++){
                    for (char c='a';c<='z';c++){
                        word[j]=c;
                        if (word!=ogWord){
                            if (st.find(word)!=st.end()){
                                q.push(word);
                                st.erase(word);
                            }
                        }
                    }
                    word=ogWord;
                }
            }
            len++;
        }

        return 0;
    }
};
