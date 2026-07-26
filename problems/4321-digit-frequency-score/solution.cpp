class Solution {
public:
    int digitFrequencyScore(int n) {
        int score=0;
        unordered_map<int,int> mpp;
        while (n){
            int digit=n%10;
            mpp[digit]++;
            n=n/10;
        }
        for (auto it : mpp){
            int digit=it.first;
            int freq=it.second;
            score+=digit*freq;
        }
        return score;
    }
};
