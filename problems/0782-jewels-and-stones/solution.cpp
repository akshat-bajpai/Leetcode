class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> st(jewels.begin(),jewels.end());
        int total=0;
        for (int i=0;i<stones.size();i++){
            if (st.find(stones[i])!=st.end()) total++;
        }
        return total;
    }
};
