class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>> adj(n);
        for (int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        int smallestNumberOfCities=INT_MAX;
        int ans=0;
        for (int i=0;i<n;i++){
            vector<int> dist(n,1e9);
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
            dist[i]=0;
            pq.push({0,i});
            while (!pq.empty()){
                int node=pq.top().second;
                int d=pq.top().first;
                pq.pop();
                if (d>dist[node]) continue;
                for (auto it : adj[node]){
                    int adjNode=it.first;
                    int edgeWeight=it.second;
                    if (dist[adjNode]>d+edgeWeight){
                        dist[adjNode]=d+edgeWeight;
                        pq.push({dist[adjNode],adjNode});
                    }
                }
            }
            int count=0;
            for (int j=0;j<n;j++){
                if (dist[j]<=distanceThreshold && j!=i) count++;
            }
            if (count<=smallestNumberOfCities){
                ans=i;
                smallestNumberOfCities=count;
            }
        }
        return ans;
    }
};
