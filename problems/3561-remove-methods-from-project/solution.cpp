class Solution {
public:
    void dfs(int start, vector<vector<int>>& adj, vector<int>& vis){
        vis[start]=1;
        for (auto adjNode:adj[start]){
            if (!vis[adjNode]){
                dfs(adjNode,adj,vis);
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<int> visFromK(n,0);
        vector<vector<int>> adj(n);
        for (int i=0;i<invocations.size();i++){
            adj[invocations[i][0]].push_back(invocations[i][1]);
        }
        dfs(k,adj,visFromK);
        vector<int> vis(n,0);
        vector<int> defans;
        for (int i=0;i<n;i++){
            defans.push_back(i);
        }
        for (int i=0;i<n;i++){
            if (!visFromK[i]){
                queue<int> q;
                vis[i]=1;
                q.push(i);
                while (!q.empty()){
                    int top=q.front();
                    q.pop();
                    for (auto it : adj[top]){
                        if (!vis[it]){
                            vis[it]=1;
                            q.push(it);
                        }
                        if (visFromK[it]){
                            return defans;
                        }
                    }
                }
            }
        }
        vector<int> ans;
        for (int i=0;i<n;i++){
            if (!visFromK[i]) ans.push_back(i);
        }
        return ans;
    }
};
