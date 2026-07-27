class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char,int> vowels;
        unordered_map<char,int> conso;
        for (int i=0;i<s.size();i++){
            if (s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                vowels[s[i]]++;
            }else{
                conso[s[i]]++;
            }
        }
        int f1=0,f2=0;
        for (auto it : vowels){
            f1=max(f1,it.second);
        }
        for (auto it : conso){
            f2=max(f2,it.second);
        }
        return f1+f2;
    }
};
