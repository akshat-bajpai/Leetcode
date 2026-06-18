class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> merged(m+n);
        int i=0,j=0;
        int ind=0;
        while (i<m && j<n){
            if (nums1[i]<nums2[j]){
                merged[ind]=nums1[i];
                ind++;i++;
            }else{
                merged[ind]=nums2[j];
                ind++;j++;
            }
        }
        while (i<m){
            merged[ind]=nums1[i];
            ind++;i++;
        }
        while (j<n){
            merged[ind]=nums2[j];
            ind++;j++;
        }
        for (int i=0;i<m+n;i++){
            nums1[i]=merged[i];
        }
    }
};
