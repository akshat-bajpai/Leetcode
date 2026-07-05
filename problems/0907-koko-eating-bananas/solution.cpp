class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=piles[0];
        for (int i=0;i<piles.size();i++){
            high=max(high,piles[i]);
        }
        int ans=-1;
        while (low<=high){
            int mid=low+(high-low)/2;
            long long tot=0;
            for (int i=0;i<piles.size();i++){
                tot+=(piles[i]+mid-1)/mid;
            }
            if (tot>h) low=mid+1;
            else{
                ans=mid;
                high=mid-1;
            }
        }
        return ans;
    }
};
