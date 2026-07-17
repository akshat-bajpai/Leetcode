class Solution {
public: 
    int timer=1;
    void dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& vis, vector<int>& tin, vector<int>& low, vector<vector<int>>& edges){
        vis[node]=1;
        tin[node]=timer;
        low[node]=timer;
        timer++;
        for (auto adjNode : adj[node]){
            if (!vis[adjNode]){
                dfs(adjNode,node,adj,vis,tin,low,edges);
                low[node]=min(low[node],low[adjNode]);
            }else{
                if (adjNode!=parent){
                    low[node]=min(low[node],low[adjNode]);
                }
            }
        }
        if (parent!=-1 && low[node]>tin[parent]){
            edges.push_back({{node,parent}});
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for (int i=0;i<connections.size();i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        vector<int> vis(n,0);
        vector<int> tin(n);
        vector<int> low(n);
        vector<vector<int>> edges;
        dfs(0,-1,adj,vis,tin,low,edges);
        return edges;
    }
};
