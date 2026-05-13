class Solution {
public:
    bool helper(vector<vector<int>>& graph, vector<int>& color, int i){
        int n=graph.size();
        queue<int>q;
        color[i]=0;
        q.push(i);
        while (!q.empty()){
            int s=q.size();
            for (int i=0;i<s;i++){
                int t=q.front();
                q.pop();
                for (auto it : graph[t]){
                    if (color[it]==-1){
                        if (color[t]==0){
                            color[it]=1;
                        }else{
                            color[it]=0;
                        }
                        q.push(it);
                    }else if (color[it]==color[t]){
                        return false;
                    }
                }
            }
        }
        return true;   
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1);
        for (int i=0;i<n;i++){
            if (color[i]==-1){
                if (helper(graph,color,i)==false) return false;
            }
        }
        return true;
    }
};
