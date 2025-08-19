class Solution {
public:
    string reverseWords(string s) {
        string word="";
        stack <string> words;
        for (char c : s){
            if (c==' '){
                if (word!="") {
                    words.push(word);
                    word="";
                }
            }
            else{
                word+=c;
            }
        }
        if (word!=""){
            words.push(word);
            word="";
        }
        string ans="";
        while (!words.empty()){
            ans+=words.top();
            words.pop();
            if (words.size()){
                ans+=" ";
            }
        }
        return ans;
    }
};
