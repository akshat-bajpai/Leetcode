class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n=nums1.size();
        long long ans=0;
        int avl=k1+k2;
        int maxDif=0;
        int res=0;
        for (int i=0;i<n;i++) {
            nums1[i]=abs(nums1[i]-nums2[i]);
            maxDif=max(maxDif,nums1[i]);
        }
        int l=0,r=maxDif;
        while (l <= r) {
            int mid =l+(r-l)/2;
            long long sum=0;
            for (int i=0;i<nums1.size();i++){
                sum+=nums1[i]>mid?nums1[i]-mid:0;
            }
            if (sum<=avl) {
                r=mid-1;
                res=mid;
            }else{
                l=mid + 1;
            }
        }
        for (int i=0;i<n;i++) {
            if (nums1[i]>res) {
                avl-=(nums1[i]-res);
            }
        }
        sort(nums1.begin(), nums1.end(), greater<int>());
        for (int num : nums1) {
            long long diff = res >= num ? num : res;
            if (avl && diff) {
                diff--;
                avl--;
            }
            ans += diff*diff;
        }
        return ans;
    }
};
