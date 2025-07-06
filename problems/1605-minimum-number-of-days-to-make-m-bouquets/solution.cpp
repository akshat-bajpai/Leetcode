class Solution {
public:
    bool blooms(vector<int>&bloomDay,int m,int k, int day){
        int boq=m;
        int c=0;
        for (int i=0;i<bloomDay.size();i++){
            if (i==0 && bloomDay[i]<=day)c++;
            else{
                if (bloomDay[i]<=day)c++;
                else c=0;
            }
            if (c==k){
                boq--;
                c=0;
            }
            if (boq<=0) return true;
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
       
        int high=INT_MIN;
        int low=INT_MAX;
        for (int i=0;i<bloomDay.size();i++){
            high=max(high,bloomDay[i]);
            low=min(low,bloomDay[i]);
        }
        int ans=-1;
        while (low<=high){
            int mid=low+(high-low)/2;
            if (blooms(bloomDay,m,k,mid)==true){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans; 

    }
};
