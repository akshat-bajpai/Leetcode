class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<vector<int>>> dp(r,vector<vector<int>>(c,vector<int>(c,-1e8)));
        //DP[i][j1][j2]
        dp[0][0][c-1]= c==1?grid[0][0] : grid[0][0]+grid[0][c-1];
        vector<int> del={-1,0,1};
        for (int i=0;i<r;i++){
            for (int j1=0;j1<c;j1++){
                for (int j2=0;j2<c;j2++){
                    if (i==0) continue;
                    for (int dj1=0;dj1<3;dj1++){
                        for (int dj2=0;dj2<3;dj2++){
                            int nj1=j1+del[dj1];
                            int nj2=j2+del[dj2];
                            if (nj1<0 || nj2<0 || nj1>=c || nj2>=c) continue;
                            if (j1==j2){
                                dp[i][j1][j2]=max(dp[i][j1][j2],grid[i][j1]+dp[i-1][nj1][nj2]);
                            }else{
                                dp[i][j1][j2]=max(dp[i][j1][j2],grid[i][j1]+grid[i][j2]+dp[i-1][nj1][nj2]);
                            }
                        }
                    }
                }
            }
        }

        int answer=INT_MIN;

        for (int i=0;i<c;i++){
            for (int j=0;j<c;j++){
                answer=max(answer,dp[r-1][i][j]);
            }
        }

        return answer;
    }
};
