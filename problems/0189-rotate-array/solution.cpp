class Solution {
public:
    void reverse(vector<int>& arr,int start,int end){
        while (start<end){
            int temp=arr[start];
            arr[start]=arr[end];
            arr[end]=temp;
            start++;
            end--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        reverse(nums,0,n-k%n-1);
        reverse(nums,n-k%n,n-1);
        reverse(nums,0,n-1);
    }
        
};
