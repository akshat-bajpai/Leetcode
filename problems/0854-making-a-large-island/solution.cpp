class DisjointSet{
public:
    vector<int> size,parent;
    DisjointSet(int n){
        size.resize(n);
        parent.resize(n);
        for (int i=0;i<n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    int findUParent(int node){
        if (parent[node]==node) return node;
        return parent[node]=findUParent(parent[node]);
    }
    void unionBySize(int u, int v){
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
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int dr[]={0,0,1,-1};
        int dc[]={1,-1,0,0};
        DisjointSet ds(n*n);
        int ans=0;

        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                if (grid[i][j]==1){
                    for (int dir=0;dir<4;dir++){
                        int nrow=i+dr[dir];
                        int ncol=j+dc[dir];
                        if (nrow>=0 && ncol>=0 && nrow<n && ncol<n && grid[nrow][ncol]==1){
                            ds.unionBySize(n*nrow+ncol,n*i+j);
                        }
                    }
                }
            }
        }
        if (ds.size[ds.findUParent(0)]==n*n) return n*n;
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                if (grid[i][j]==0){
                    int size=1;
                    set<int> st;
                    for (int dir=0;dir<4;dir++){
                        int nrow=i+dr[dir];
                        int ncol=j+dc[dir];
                        if (nrow>=0 && ncol>=0 && nrow<n && ncol<n && grid[nrow][ncol]==1){
                            if (st.find(ds.findUParent(n*nrow+ncol))==st.end()){
                                st.insert(ds.findUParent(n*nrow+ncol));
                                size+=ds.size[ds.findUParent(n*nrow+ncol)];
                            }
                        }
                    }
                    ans=max(ans,size);
                }
            }
        }
        return ans;
    }
};
