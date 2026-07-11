class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> vis(n,0);
        int numConnectedComplete=0;
        for (int i=0;i<n;i++){
            if (!vis[i]){
                queue<int> q;
                vis[i]=1;
                q.push(i);
                vector<int> nodes;
                while (!q.empty()){
                    int node=q.front();
                    q.pop();
                    nodes.push_back(node);
                    for (auto it : adj[node]){
                        if (!vis[it]){
                            q.push(it);
                            vis[it]=1;
                        }
                    }
                }
                int totalNodes=nodes.size();
                bool eligible=true;
                for (int node : nodes) {
                    if (adj[node].size() == totalNodes - 1) continue;
                    eligible = false;
                    break; 
                }
                if (eligible) numConnectedComplete++;
            }
        }
        return numConnectedComplete;
    }
};
