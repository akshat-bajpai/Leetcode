class DisjointSet{
    vector<int> size,parent;
public:
    DisjointSet(int n){
        size.resize(n,0);
        parent.resize(n);
        for (int i=0;i<n;i++){
            parent[i]=i;
        }
    }

    int findUParent(int node){
        if (parent[node]==node) return node;
        return parent[node]=findUParent(parent[node]);
    }

    void unionBySize( int u, int v){
        int ulp_u=findUParent(u);
        int ulp_v=findUParent(v);
        if (ulp_u==ulp_v) return;
        if (size[ulp_u]<size[ulp_v]){
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
        int numberOfCables=connections.size();
        if (numberOfCables<n-1) return -1;
        DisjointSet dS(n);
        int components=0;
        for (int i=0;i<connections.size();i++){
            int u=connections[i][0];
            int v=connections[i][1];
            dS.unionBySize(u,v);
        }
        for (int i=0;i<n;i++){
            if (dS.findUParent(i)==i) components++;
        }

        return components-1;
    }
};
