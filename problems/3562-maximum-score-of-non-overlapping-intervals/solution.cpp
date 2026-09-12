class Solution {
public:
    static bool comp(vector<int> a, vector<int> b) {
        return a[1] < b[1];
    }
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        for (int i =0;i < n; i++) {
            intervals[i].push_back(i);
        }
        sort(intervals.begin(),intervals.end(),comp);
        vector<int> prev(n,-1);
        for (int i=1;i<n;i++) {
            int low=0;
            int high=i-1;
            while (low<=high) {
                int mid=low+(high-low)/2;
                if (intervals[mid][1] < intervals[i][0]) {
                    prev[i] = mid;
                    low = mid + 1;
                } 
                else {
                    high = mid - 1;
                }
            }
        }
        vector<vector<pair<long long,vector<int>>>> dp(n,vector<pair<long long,vector<int>>>(5));
        for (int j=1;j<=4;j++) {
            dp[0][j].first=intervals[0][2];
            dp[0][j].second={intervals[0][3]};
        }
        for (int i=1;i<n;i++) {
            for (int j = 1; j <= 4; j++) {
                auto notPick =dp[i-1][j];
                pair<long long, vector<int>> pick;
                pick.first=intervals[i][2];
                if (prev[i]!=-1) {
                    pick.first+=dp[prev[i]][j-1].first;
                    pick.second=dp[prev[i]][j-1].second;
                }
                pick.second.push_back(intervals[i][3]);
                sort(pick.second.begin(),pick.second.end());
                if (pick.first>notPick.first){
                    dp[i][j]=pick;
                }else if (pick.first<notPick.first){
                    dp[i][j]=notPick;
                }else{
                    if (pick.second<notPick.second) dp[i][j]=pick;
                    else dp[i][j]=notPick;
                }
            }
        }
        // vector<int> ans;
        // int i=n-1;
        // int j=4;

        // while (i>=0 && j>0) {
        //     if (i>0 && dp[i][j]==dp[i-1][j]){
        //         i--;
        //     }
        //     else {
        //         ans.push_back(intervals[i][3]);
        //         i=prev[i];
        //         j--;
        //     }
        // }
        // sort(ans.begin(), ans.end());
        return dp[n-1][4].second;
    }
};
