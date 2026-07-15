class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto it : edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        int answerCity=0;
        int mini=INT_MAX;
        for (int city=0;city<n;city++){
            vector<int> dist(n,1e9);
            dist[city]=0;
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
            pq.push({0,city});
            while (!pq.empty()){
                int d=pq.top().first;
                int node=pq.top().second;
                pq.pop();
                for (auto it : adj[node]){
                    int adjNode=it.first;
                    int eW=it.second;
                    if (dist[adjNode]>d+eW){
                        dist[adjNode]=d+eW;
                        pq.push({d+eW,adjNode});
                    }
                }
            }
            int c=0;
            for (int i=0;i<n;i++){
                if (dist[i]<=distanceThreshold) c++;
            }
            if (c<=mini){
                mini=c;
                answerCity=city;
            }
        }
        return answerCity;
    }
};
