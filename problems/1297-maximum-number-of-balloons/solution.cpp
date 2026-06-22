class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map<char,int> mpp;
        vector<char> balloon={'b','a','l','o','n'};
        for (int i=0;i<balloon.size();i++){
            mpp[balloon[i]]=0;
        }
        for (int i=0;i<text.size();i++){
            for (int j=0;j<balloon.size();j++){
                if (text[i]==balloon[j]){
                    mpp[text[i]]++;
                }
            }
        }
        int limiting=INT_MAX;
        for (auto it : mpp){
            if (it.first=='l' || it.first=='o'){
                limiting=min(limiting,it.second/2);
            }else{
                limiting=min(limiting,it.second);
            }
        }
        return limiting;
    }
};
