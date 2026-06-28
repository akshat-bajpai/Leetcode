class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int lastVal=1;
        int maxVal=1;
        for (int i=1;i<arr.size();i++){
            if (abs(lastVal-arr[i])<=1){
                maxVal=max(arr[i],maxVal);
                lastVal=arr[i];
            }else{
                int newVal=lastVal+1;
                lastVal=newVal;
                maxVal=lastVal;
            }
        }
        return maxVal;
    }
};
