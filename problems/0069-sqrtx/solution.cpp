class Solution {
public:
    int mySqrt(int x) {
        long long low=0;
        long long high=x;
        int ans=0;

        while (low<=high){
            long long mid=low+(high-low)/2;
            long long val=mid*mid;
            if (val==x) return mid;
            if (val<x){
                ans=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return ans;
    }
};
