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
            long long time=0;
            for (int i=0;i<piles.size();i++){
                time+=(piles[i]+mid-1)/mid;
            }
            if (time<=h) {
                ans=mid;
                high=mid-1;
            }
            else if (time>h) low=mid+1;
            else high=mid-1;
        }
        return ans;
    }
};
