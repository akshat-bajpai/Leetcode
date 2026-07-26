class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        int n=order.size();
        unordered_set<int> st(friends.begin(),friends.end());
        vector<int> ans;
        for (int i=0;i<order.size();i++){
            if (st.find(order[i])!=st.end()){
                ans.push_back(order[i]);
            }
        }
        return ans;
    }
};
