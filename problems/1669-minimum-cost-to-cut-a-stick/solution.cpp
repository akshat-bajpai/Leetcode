class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int c=cuts.size();

        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());

        vector<vector<long long>> dp(c+2,vector<long long>(c+2,0));

        for (int i=c;i>=1;i--){
            for (int j=i;j<=c;j++){
                long long mini=1e9;
                for (int ind=i;ind<=j;ind++){
                    mini=min(mini,dp[i][ind-1]+dp[ind+1][j]+cuts[j+1]-cuts[i-1]);
                }
                dp[i][j]=mini;
            }

        }

        return dp[1][c];
    }
};
