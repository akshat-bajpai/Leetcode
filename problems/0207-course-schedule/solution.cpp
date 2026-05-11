class Solution {
public:
    //basically a deadlock type detection/ directed cycle detection i guess
    bool dfs(int numCourses,vector<vector<int>>& adj, int node,vector<int>& vis){
        vis[node]=1;
        for (auto adjNode : adj[node]){
            if (vis[adjNode]==0){
                if (dfs(numCourses,adj,adjNode,vis)) return true;
            }else if (vis[adjNode]==1){
                return true;
            }
        }
        vis[node]=2;
        return false;
    }
    bool detectCycle(int numCourses,vector<vector<int>>& adj,vector<int>& vis){
        for (int i=0;i<numCourses;i++){
            if (vis[i]==0){
                if (dfs(numCourses,adj,i,vis)==true) return true;
            }
        }
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for (int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<int>visited(numCourses,0);
        if (detectCycle(numCourses,adj,visited)==true) return false;
        return true;
    }
};
