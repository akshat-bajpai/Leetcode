class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int> mpp;
        if (hand.size()%groupSize!=0) return false;
        for (int i=0;i<hand.size();i++){
            if (mpp.find(hand[i])==mpp.end()){
                mpp[hand[i]]=1;
            }else{
                mpp[hand[i]]++;
            }
        }
        auto it=mpp.begin();
        while (it!=mpp.end()){
            if (it->second==0){
                it++;
                continue;
            } 
            int start=it->first;
            for (int i=0;i<groupSize;i++){
                if (mpp[start+i]==0){
                    return false;
                }
                mpp[start+i]--;
            }
            if (mpp[start]==0) it++;
        }
        return true;
    }
};
