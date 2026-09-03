class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        sort(nums1.begin(),nums1.end());
        unordered_map<int,int> mpp;
        bool odd_before=false;
        bool set=false;

        for(int i=0;i<nums1.size();i++){
            int number=nums1[i]%2;
            mpp[number]++;
            if(!set){
                if(number==1)odd_before=true;
                else{
                    odd_before=false;
                }
                set=true;
            }
        }
        if(mpp[0]==0 ||mpp[1]==0){
            return true;
        }
        if(mpp[0]>=1 && mpp[1]>=1){
            return odd_before;
        }
        return true;
    }
};

