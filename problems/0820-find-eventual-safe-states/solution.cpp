class Solution {
public:
    bool dfs_cyc(int node, vector<vector<int>>& graph, vector<int>& vis, vector<int>& pathVis){
        vis[node]=1;
        pathVis[node]=1;
        for (auto it : graph[node]){
            if (!vis[it] && !pathVis[it]){
                if (dfs_cyc(it,graph,vis,pathVis)) return true;
            }else if (pathVis[it]){
                return true;
            }
        }
        pathVis[node]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n,0);
        vector<int> pathVis(n,0);
        for (int i=0;i<n;i++){
            if (!vis[i]){
                dfs_cyc(i,graph,vis,pathVis);
            }
        }
        vector<int> ans;
        for (int i=0;i<n;i++){
            if (pathVis[i]==0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
