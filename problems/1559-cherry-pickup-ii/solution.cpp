class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        //dp[i][j][r]=max cherries collected when robot 1 is at i, 2 is at j and their row is r
        vector<vector<vector<int>>> dp(cols, vector<vector<int>>(cols,vector<int>(rows,-1)));
        dp[0][cols-1][0]=(0==cols-1)?grid[0][0]:grid[0][0]+grid[0][cols-1];
        //dp[i][j][r]
        // -> dp[i][j][r-1]
        // -> dp[i][j-1][r-1]
        // -> dp[i][j+1][r-1]
        for (int r=1;r<rows;r++){
            for (int i=0;i<cols;i++){
                for (int j=cols-1;j>=0;j--){
                    for (int d1=-1;d1<=1;d1++){
                        for (int d2=-1;d2<=1;d2++){
                            int pi=i+d1;
                            int pj=j+d2;
                            if (pi<0 || pj<0 || pi>=cols || pj>= cols ||dp[pi][pj][r-1]==-1 ) continue;
                            dp[i][j][r]=max(dp[i][j][r],dp[pi][pj][r-1]+(i==j?grid[r][i]:grid[r][i]+grid[r][j]));
                        }
                    }
                }
            }
        }
        int ans=dp[0][0][rows-1];
        for (int i=0;i<cols;i++){
            for (int j=0;j<cols;j++){
                ans=max(ans,dp[i][j][rows-1]);
            }
        }
        return ans;
    }
};
