class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size(),n=obstacleGrid[0].size();
        vector<int> prev(n,0);
        for (int i=0;i<m;i++){
            vector<int> temp(n,0);
            for (int j=0;j<n;j++){
                if (i==0 && j==0){
                    if (obstacleGrid[i][j]==1) return 0;
                    temp[j]=1;
                }
                if(obstacleGrid[i][j]==1) continue;
                if (i-1>=0 && obstacleGrid[i-1][j]==0) temp[j]+=prev[j];
                if (j-1>=0 && obstacleGrid[i][j-1]==0) temp[j]+=temp[j-1];
            }
            prev=temp;
        }
        return prev[n-1];
    }
};
