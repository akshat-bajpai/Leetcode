class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>> adj(n);
        for (int i=0;i<n;i++){
            for (auto it : graph[i]){
                adj[it].push_back(i);
            }
        }
        vector<int> inDegree(n);
        for (int i=0;i<n;i++){
            for (auto it : adj[i]){
                inDegree[it]++;
            }
        }

        queue<int> q;

        for (int i=0;i<n;i++){
            if (inDegree[i]==0){
                q.push(i);
            }
        }
        vector<int> ans;
        while (!q.empty()){
            int node=q.front();
            q.pop();
            for (auto it : adj[node]){
                inDegree[it]--;
                if (inDegree[it]==0) q.push(it);
            }
            ans.push_back(node);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
