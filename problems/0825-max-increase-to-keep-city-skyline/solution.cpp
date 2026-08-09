class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int> ns(n,0);
        vector<int> ew(n,0);
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                ew[i]=max(ew[i],grid[i][j]);
                ns[j]=max(ns[j],grid[i][j]);
            }
        }
        int maxi=0;
        for (int i=0;i<grid.size();i++){
            for (int j=0;j<grid.size();j++){
                maxi+=min(ns[i],ew[j])-grid[i][j];
            }
        }
        return maxi;
    }
};
