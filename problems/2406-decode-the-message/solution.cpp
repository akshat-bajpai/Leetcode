class Solution {
public:
    string decodeMessage(string key, string message) {
        vector<int> mapping(26,-1);
        char curr=0;
        for (int i=0;i<key.size();i++){
            if (key[i]==' ') continue;
            if (mapping[key[i]-'a']==-1){
                mapping[key[i]-'a']=curr;
                curr++;
            }
        }
        string ans;
        for (int i=0;i<message.size();i++){
            if (message[i]==' '){
                ans+=' ';
                continue;
            }
            ans+=(mapping[message[i]-'a']+'a');
        }
        return ans;
    }
};
