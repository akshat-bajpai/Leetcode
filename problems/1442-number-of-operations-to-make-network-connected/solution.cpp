class DisjointSet{
    vector<int> size, parent;
public:
    DisjointSet(int n){
        size.resize(n,1);
        parent.resize(n);
        for (int i=0;i<n;i++){
            parent[i]=i;
        }
    }

    int findUParent(int node){
        if (parent[node]==node) return node;
        return parent[node]=findUParent(parent[node]);
    }

    void unionBySize(int u, int v){
        int ulp_u=findUParent(u);
        int ulp_v=findUParent(v);
        if (ulp_v==ulp_u) return;
        if (size[ulp_v]>size[ulp_u]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int numCables=connections.size();
        if (numCables<n-1) return -1;
        DisjointSet ds(n);
        for (int i=0;i<connections.size();i++){
            ds.unionBySize(connections[i][0],connections[i][1]);
        }
        int components=0;
        for (int i=0;i<n;i++){
            if (ds.findUParent(i)==i) components++;
        }
        return components-1;
    }
};
