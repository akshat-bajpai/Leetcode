class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        if (nums.size()==1) return 1;
        int n=nums.size();
        int mini=nums[0];
        int maxi=nums[0];
        int minIndex=0;
        int maxIndex=0;
        for (int i=1;i<n;i++){
            if (nums[i]<mini){
                mini=nums[i];
                minIndex=i;
            }
            if (nums[i]>maxi){
                maxi=nums[i];
                maxIndex=i;
            }
        }
        int totSteps=0;
        int firstIndex=min(minIndex,maxIndex);
        int secondIndex=max(minIndex,maxIndex);
        if (firstIndex+1<n-secondIndex){
            totSteps+=firstIndex+1;
            totSteps+=min(n-secondIndex,secondIndex-firstIndex);
        }else{
            totSteps+=n-secondIndex;
            totSteps+=min(firstIndex+1,secondIndex-firstIndex);
        }
        // totSteps=min(firstIndex+1,n-secondIndex);
        return totSteps;

    }
};
