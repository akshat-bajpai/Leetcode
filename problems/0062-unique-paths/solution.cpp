class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int>prev(n,1);
        //dp[i][j]=number of ways to reach i,j
        //come from above: i-1,j ; come from left: i,j-1;

        for (int i=1;i<m;i++){
            vector<int> curi=prev;
            for (int j=1;j<n;j++){
                curi[j]=prev[j]+curi[j-1];
            }
            prev=curi;
        }
        return prev[n-1];
    }
};
