class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for (int i=0;i<times.size();i++){
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        vector<int> dist(n+1,INT_MAX);
        dist[k]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});
        while (!pq.empty()){
            int d=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for (auto it : adj[node]){
                int adjNode=it.first;
                int edgeWeight=it.second;
                if (dist[adjNode]>d+edgeWeight){
                    dist[adjNode]=d+edgeWeight;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }
        int ans=-1;
        for (int i=1;i<dist.size();i++){
            if (dist[i]==INT_MAX) return -1;
            ans=max(ans,dist[i]);
        }
        return ans;
    }
};
