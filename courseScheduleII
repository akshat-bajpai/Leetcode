class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        vector<vector<int>>adj(numCourses);
        for (int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int>inDegree(numCourses,0);
        for (int i=0;i<prerequisites.size();i++){
            inDegree[prerequisites[i][0]]++;
        }
        queue<int>q;
        for (int i=0;i<numCourses;i++){
            if (inDegree[i]==0)q.push(i);
        }
        while (!q.empty()){
            int node=q.front();
            q.pop();
            for (auto it : adj[node]){
                inDegree[it]--;
                if (inDegree[it]==0) q.push(it);
            }
            ans.push_back(node);
        }
        if (ans.size()==numCourses) return ans;
        else return {};
    }
};
