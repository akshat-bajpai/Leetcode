class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto it : prerequisites){
            adj[it[0]].push_back(it[1]);
        }
        vector<int> indegree(numCourses);
        for (int i=0;i<prerequisites.size();i++){
            indegree[prerequisites[i][1]]++;
        }
        queue<int> q;
        for (int i=0;i<numCourses;i++){
            if (indegree[i]==0) q.push(i);
        }
        int topo=0;
        while (!q.empty()){
            int node=q.front();
            topo++;
            q.pop();
            for (auto it : adj[node]){
                indegree[it]--;
                if (indegree[it]==0) q.push(it);
            }
        }
        return topo==numCourses;
    }
};
