class Solution {
public:
    bool dfs(int node,vector<vector<int>>& graph,vector<int>& vis, int col){
        vis[node]=col;
        for (auto it : graph[node]){
            if (!vis[it]){
                if (!dfs(it,graph,vis,col==1?2:1)) return false;
            }else{
                if (vis[it]==col){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> vis(graph.size(),0);
        for (int i=0;i<graph.size();i++){
            if (!vis[i]){
                if (!dfs(i,graph,vis,1)) return false;
            }
        }
        return true;
    }
};
