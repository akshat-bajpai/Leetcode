class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        unordered_set<int> st;
        int c=0;
        st.insert(nums[0]);
        st.insert(nums[1]);
        for (int i=2;i<nums.size();i++){
            st.insert(nums[i]);
            if (st.find(nums[i]-diff)==st.end()) continue;
            int num2=nums[i]-diff;
            if (st.find(num2-diff)==st.end()) continue;
            c++;

        }
        return c;
    }
};
