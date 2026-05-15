class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for (int i=0;i<flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]}); //u->(v,w)
        }
        vector<int>dist(n,1e9);
        queue<vector<int>>q;
        q.push({src,0,0}); //node,distance,edges
        dist[src]=0;
        while (!q.empty()){
            int node=q.front()[0];
            int d=q.front()[1];
            int edges=q.front()[2];
            q.pop();
            if (edges==k+1 ) continue;
            for (auto it : adj[node]){
                int adjNode=it.first;
                int edgeWeight=it.second;
                if (dist[adjNode]>d+edgeWeight){
                    dist[adjNode]=d+edgeWeight;
                    q.push({adjNode,dist[adjNode],edges+1});
                }
            }
        }
        if (dist[dst]==1e9) return -1;
        else return dist[dst];
    }
};
