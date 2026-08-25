class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n=nums.size();
        int multi=k;
        unordered_set<int> st(nums.begin(),nums.end());
        while (true){
            if (st.find(k)==st.end()) return k;
            k+=multi;
        }
        return -1;
    }
};
