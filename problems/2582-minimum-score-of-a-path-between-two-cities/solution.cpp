class Solution {
public:
    vector<vector<pair<int, int>>> graph;
    vector<int> visited;
    int ans;
    void dfs(int node) {
        visited[node] = 1;
        for (int i = 0; i < graph[node].size(); i++) {
            int nei = graph[node][i].first;
            int dist = graph[node][i].second;
            if (dist < ans) {
                ans = dist;
            }
            if (visited[nei] == 0) {
                dfs(nei);
            }
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {
        graph.resize(n + 1);
        visited.resize(n + 1, 0);
        for (int i = 0; i < roads.size(); i++) {
            int u = roads[i][0];
            int v = roads[i][1];
            int d = roads[i][2];
            graph[u].push_back({v, d});
            graph[v].push_back({u, d});
        }
        ans = INT_MAX;
        dfs(1);
        return ans;
    }
};
