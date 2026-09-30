class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> ans;
        int n=seq.size();
        for (int i=0;i<n;i++){
            ans.push_back((i^seq[i])&1);
        }
        return ans;
    }
};
