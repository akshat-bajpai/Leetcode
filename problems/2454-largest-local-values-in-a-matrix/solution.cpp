class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> maxLocal(n-2,vector<int>(n-2));
        for (int i=0;i<n-2;i++){
            for (int j=0;j<n-2;j++){
                int localMaxi=grid[i][j];
                for (int di=0;di<3;di++){
                    for (int dj=0;dj<3;dj++){
                        localMaxi=max(localMaxi,grid[i+di][j+dj]);
                    }
                }
                maxLocal[i][j]=localMaxi;
            }
        }
        return maxLocal;
    }
};
