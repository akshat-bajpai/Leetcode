class Solution {
public:
    bool dfsCycle(int numCourses,vector<vector<int>>& adj, int node, vector<int>& vis){
        vis[node]=1;
        for (auto it : adj[node]){
            if (!vis[it]){
                if (dfsCycle(numCourses,adj,it,vis)) return true;
            }else{
                if (vis[it]==1) return true;
            }
        }
        vis[node]=2;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<int> vis(numCourses,0);
        for (int i=0;i<numCourses;i++){
            if (!vis[i]){
                if (dfsCycle(numCourses,adj,i,vis)) return false;
            }
        }
        return true;
    }
};
