class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> cnt;
        for (int num : nums){
            cnt[num]++;
        }
        int ans=0;
        if (cnt[1]%2==0){
            ans=cnt[1]-1;
        }else{
            ans=cnt[1];
        }
        cnt.erase(1);
        for (auto it : cnt){
            int res=0;
            long long x=it.first;
            while (cnt.contains(x) && cnt[x]>1){
                res+=2;
                x*=x;
            }
            ans=max(ans,res+(cnt.contains(x)?1:-1));
        }
        return ans;
    }
};
