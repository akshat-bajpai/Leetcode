class Solution {
public:
    int timer=1;
    void dfs(vector<vector<int>>& adj, vector<int>& vis, int node, int parent,vector<int>& tin, vector<int>& low,vector<vector<int>>& bridges){
        vis[node]=1;
        tin[node]=timer;
        low[node]=timer;
        timer++;

        for (auto it : adj[node]){
            if (it==parent) continue;
            if (vis[it]==0){
                dfs(adj,vis,it,node,tin,low,bridges);
                low[node]=min(low[node],low[it]);
                if (low[it]>tin[node]){
                    bridges.push_back({it,node});
                }
            }else{
                low[node]=min(low[node],low[it]);
            }
        }

    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> vis(n,0);
        vector<vector<int>> adj(n);
        vector<int> tin(n);
        vector<int> low(n);
        for (int i=0;i<connections.size();i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        vector<vector<int>> bridges;
        dfs(adj,vis,0,-1,tin,low,bridges);
        return bridges;
    }
};
