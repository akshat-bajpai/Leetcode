class Solution {
public:
    void dfs(int node,vector<vector<int>>& isConnected, vector<int>& vis){
        int n=isConnected.size();
        vis[node]=1;
        for (int i=0;i<n;i++){
            if (isConnected[node][i]==1 && vis[i]==0 && node!=i){
                dfs(i,isConnected,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int numProvince=0;
        int n=isConnected.size();
        vector<int> vis(n,0);
        for (int i=0;i<n;i++){
            if (vis[i]==0){
                numProvince++;
                dfs(i,isConnected,vis);
            }
        }
        return numProvince;
    }
};
