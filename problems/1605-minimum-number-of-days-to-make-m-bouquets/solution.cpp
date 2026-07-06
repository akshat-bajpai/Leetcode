class Solution {
public:
    bool possible(vector<int>& bloomDay, int m, int k, int day){
        int tot=0;
        int curr=0;
        for (int i=0;i<bloomDay.size();i++){
            if (bloomDay[i]<=day){
                curr++;
                if (curr==k){
                    tot++;
                    curr=0;
                }
            }else{
                curr=0;
            }
        }
        if (tot>=m) return true;
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if ((long long)m*k>n) return -1;
        int low=1;
        int high=bloomDay[0];
        for (int i=1;i<n;i++){
            high=max(high,bloomDay[i]);
        }

        while (low<=high){
            int mid=low+(high-low)/2;
            if (possible(bloomDay,m,k,mid)){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }

        return low;
    }
};
