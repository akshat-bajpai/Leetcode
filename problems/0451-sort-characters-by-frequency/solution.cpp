class Solution {
public:
    string frequencySort(string s) {
        map<char,int> mpp;
        for (int i=0;i<s.size();i++){
            mpp[s[i]]++;
        }
        vector<pair<int,char>>a;
        for (auto it : mpp){
            a.push_back({it.second,it.first});
        }
        sort(a.begin(),a.end());
        reverse(a.begin(),a.end());
        string answer="";
        for (int i=0;i<a.size();i++){
            for (int j=0;j<a[i].first;j++){
                answer+=a[i].second;
            }
        }
        return answer;
    }
};
