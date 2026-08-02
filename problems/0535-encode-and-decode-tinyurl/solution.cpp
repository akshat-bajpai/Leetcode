class Solution {
public:
    unordered_map<int,string> mp;
    int id=0;
    string encode(string longUrl) {
        mp[id]=longUrl;
        return to_string(id++);
    }
    string decode(string shortUrl) {
        int key=stoi(shortUrl);
        return mp[key];
    }
};
