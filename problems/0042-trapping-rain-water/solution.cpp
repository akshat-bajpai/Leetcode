class Solution {
public:
    int trap(vector<int>& height) {
        int total=0;
        int l=0;
        int lMax=0;
        int n=height.size();
        int r=n-1;
        int rMax=0;
        while (l<r){
            if (height[l]<=height[r]){
                if (height[l]<lMax){
                    total+=lMax-height[l];
                    l++;
                }else{
                    lMax=height[l];
                    l++;
                }
            }else{
                if (height[r]<rMax){
                    total+=rMax-height[r];
                    r--;
                }else{
                    rMax=height[r];
                    r--;
                }
            }
        }
        return total;
    }
};
