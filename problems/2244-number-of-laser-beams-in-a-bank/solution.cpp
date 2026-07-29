class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> modBank;
        for (int i=0;i<bank.size();i++){
            int numSec=0;
            for (int j=0;j<bank[i].size();j++){
                if (bank[i][j]=='1'){
                    numSec++;
                }
            }
            if (numSec) modBank.push_back(numSec);
        }
        int n=modBank.size();
        int ans=0;
        for (int i=0;i<n-1;i++){
            ans+=modBank[i]*modBank[i+1];
        }
        return ans;
    }
};
