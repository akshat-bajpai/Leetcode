class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        map<int,int> mpp;
        int maxi=0;
        for (int i=0;i<edges.size();i++){
            mpp[edges[i][0]]++;
            mpp[edges[i][1]]++;
            maxi=max(maxi,max(edges[i][0],edges[i][1]));
        }
        for (auto it : mpp){
            if (it.second==maxi-1) return it.first;
        }
        return 0;
    }
};
