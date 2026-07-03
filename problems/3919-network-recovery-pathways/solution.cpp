class Solution {
public:
    vector<vector<pair<int, int>>> g;
    vector<long long> dp;
    int n;
    long long k;
    int limit;
    long long dfs(int node) {
        if (node == n - 1) {
            return 0;
        }
        if (dp[node] != -1) {
            return dp[node];
        }
        long long ans = LLONG_MAX / 2;
        for (int i = 0; i < g[node].size(); i++) {
            int next = g[node][i].first;
            int wt = g[node][i].second;
            if (wt >= limit) {
                long long cur = dfs(next);
                if (cur != LLONG_MAX / 2) {
                    ans = min(ans, cur + wt);
                }
            }
        }
        dp[node] = ans;
        return ans;
    }
    bool check(int mid) {
        limit = mid;
        dp.assign(n, -1);

        long long cost = dfs(0);
        return cost <= k;
    }
    int findMaxPathScore(vector<vector<int>>& edges,vector<bool>& online,long long K) {
        n = online.size();
        k = K;
        g.assign(n, {});
        int l = INT_MAX;
        int r = 0;
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            if (!online[u] || !online[v]) {
                continue;
            }
            g[u].push_back({v, w});
            l = min(l, w);
            r = max(r, w);
        }
        if (l == INT_MAX) {
            return -1;
        }
        if (!check(l)) {
            return -1;
        }
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (check(mid)) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return r;
    }
};
