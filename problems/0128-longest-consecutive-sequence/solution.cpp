class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;

        for (int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        int ans=0;
        for (auto it : st){
            if (st.find(it-1)!=st.end()) continue;
            int c=1;
            int num=it;
            while (st.find(num+1)!=st.end()){
                c++;
                num++;
            }
            ans=max(ans,c);
        }
        return ans;
    }
};
