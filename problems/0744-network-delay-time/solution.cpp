class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for (int i=0;i<times.size();i++){
            adj[times[i][0]].push_back({times[i][1],times[i][2]}); //u->(v,w)
        }
        vector<int> dist(n+1,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        dist[k]=0;
        pq.push({0,k});
        while (!pq.empty()){
            int d=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for (auto it : adj[node]){
                int adjNode=it.first;
                int edgeWeight=it.second;
                if (dist[adjNode]>dist[node]+edgeWeight){
                    dist[adjNode]=dist[node]+edgeWeight;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }
        int t=INT_MIN;
        for (int i=1;i<n+1;i++){
            t=max(t,dist[i]);
            if (dist[i]==1e9) return -1;
        }
        return t;
    }
};
