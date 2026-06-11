class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if (nums.size()%k!=0) return false;
        map<int,int> mpp;
        for (int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        auto it = mpp.begin();
        while (it!=mpp.end()){
            if (it->second==0){
                it++;
                continue;
            }
            int start=it->first;
            int count=it->second;
            for (int i=0;i<k;i++){
                if (mpp.find(start+i)==mpp.end() || mpp[start+i]<count) return false;
                mpp[start+i]-=count;
            }
            it++;
        }
        return true;
    }
};
