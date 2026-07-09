class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, vector<int>& vis, int node){
        vis[node]=1;
        for (int i=0;i<isConnected.size();i++){
            if (isConnected[i][node] && !vis[i]){
                dfs(isConnected,vis,i);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> vis(n,0);
        int numProvince=0;
        for (int i=0;i<n;i++){
            if (!vis[i]){
                numProvince++;
                dfs(isConnected,vis,i);
            }
        }
        return numProvince;
    }
};
