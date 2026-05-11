class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n=wordList.size();
        set<string>st;
        for (int i=0;i<n;i++){
            st.insert(wordList[i]);
        }
        queue<string>q;
        q.push(beginWord);
        int t=1;
        while (!q.empty()){
            int s=q.size();
            for (int i=0;i<s;i++){
                string n=q.front();
                q.pop();
                if (n==endWord) return t;
                for (int i=0;i<n.size();i++){
                    string word=n;
                    for (char ch='a';ch<='z';ch++){
                        n[i]=ch;
                        if (st.find(n)!=st.end()){
                            st.erase(n);
                            q.push(n);
                        }
                    }
                    n=word;
                }
            }
            t++;
        }
        return 0;

    }
};
