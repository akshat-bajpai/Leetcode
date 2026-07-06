class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low=weights[0];
        int high=0;
        for (int i=0;i<weights.size();i++){
            low=max(low,weights[i]);
            high+=weights[i];
        }
        while (low<=high){
            int mid=low+(high-low)/2;
            int d=1;
            int cap=0;
            for (int i=0;i<weights.size();i++){
                if (cap+weights[i]<=mid){
                    cap+=weights[i];
                }else{
                    cap=weights[i];
                    d++;
                }
            }
            if (d<=days){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};
