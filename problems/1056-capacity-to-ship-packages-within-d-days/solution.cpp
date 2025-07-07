class Solution {
public:
    int shippable(vector<int>& weights,int days,int capacity){
        int c=0;
        int d=1;
        for (int i=0;i<weights.size();i++){
            c+=weights[i];
            if (c<=capacity){

            }else{
                c=0;
                c+=weights[i];
                d++;
            }
            if (d>days) return false;
        }
        return true;
    }


    int shipWithinDays(vector<int>& weights, int days) {
        int high=0;
        int low=INT_MIN;
        for (int i=0;i<weights.size();i++){
            high+=weights[i];
            low=max(low,weights[i]);
        }
        int ans=low;
        while (low<=high){
            int mid=low+(high-low)/2;
            if (shippable(weights,days,mid)==true){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};
