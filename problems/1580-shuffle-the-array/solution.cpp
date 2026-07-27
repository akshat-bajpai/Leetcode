class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> arr(2*n);
        int ptr1=0,ptr2=n;
        for (int i=0;i<2*n;i++){
            if (i%2==0){
                arr[i]=nums[ptr1];
                ptr1++;
            }else{
                arr[i]=nums[ptr2];
                ptr2++;
            }
        }
        return arr;
    }
};
