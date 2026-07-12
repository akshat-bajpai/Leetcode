class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<vector<int>> q;
        vector<vector<pair<int,int>>> adj(n);
        for (auto it : flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        q.push({0,src,-1});
        vector<int> dist(n,INT_MAX);
        dist[src]=0;
        while (!q.empty()){
            const auto& v = q.front();
            int d = v[0];
            int node = v[1];
            int stops = v[2];
            q.pop();
            for (auto it : adj[node]){
                int adjNode=it.first;
                int cost=it.second;
                if (stops<k){
                    if (dist[adjNode]>d+cost){
                        dist[adjNode]=d+cost;
                        q.push({dist[adjNode],adjNode,stops+1});
                    }
                }
            }
        }
        if (dist[dst]==INT_MAX) return -1;
        return dist[dst];
    }
};
