class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        for (int i=0;i<roads.size();i++){
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        long long m=1e9+7;
        vector<long long> dist(n,LLONG_MAX);
        priority_queue<pair<long long ,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        dist[0]=0;
        //priority queue -> distance,node
        pq.push({0,0});
        vector<long long>ways(n,0);
        ways[0]=1;
        while (!pq.empty()){
            int d=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if (d>dist[node]) continue;
            for (auto it : adj[node]){
                int adjNode=it.first;
                int edgeWeight=it.second;
                if (dist[adjNode]>dist[node]+edgeWeight){
                    dist[adjNode]=dist[node]+edgeWeight;
                    pq.push({dist[adjNode],adjNode});
                    ways[adjNode]=ways[node];
                }else if (dist[adjNode]==dist[node]+edgeWeight) ways[adjNode]+=ways[node]%m;
            }
        }
        return ways[n-1]%m;
    }
};
