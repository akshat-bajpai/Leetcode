class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi=INT_MIN;
        for (int i=0;i<piles.size();i++){
            maxi=max(maxi,piles[i]);
        }
        int low=1;
        int high=maxi;
        int ans=0;
        while (low<=high){
            int mid=low+(high-low)/2;
            long long hours=0;
            for (int i=0;i<piles.size();i++){
                hours+=ceil((double)piles[i]/mid);
            }
            if (hours>h) low=mid+1;
            else if (hours<=h){
                ans=mid;
                high=mid-1;
            }
            
        }
        return ans;
    }
};
