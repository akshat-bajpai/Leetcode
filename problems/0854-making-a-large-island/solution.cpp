class DisjointSet{
  public: 
    vector<int> size,parent;

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
        if(ulp_u==ulp_v) return;
        if (size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
    int sizeOfUnit(int node){
        int p=findUParent(node);
        return size[p];
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DisjointSet dS(n*n);
        int largest=0;
        int dr[4]={1,-1,0,0};
        int dc[4]={0,0,1,-1};
        int oneExists=false;
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                if (grid[i][j]==1){
                    oneExists=true;
                    for (int k=0;k<4;k++){
                        int nrow=i+dr[k];
                        int ncol=j+dc[k];
                        if (nrow<0 || ncol<0 || nrow>=n || ncol>= n || grid[nrow][ncol]==0) continue;
                        dS.unionBySize(i*n+j,nrow*n+ncol);
                    }
                }
            }
        }

        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                if (grid[i][j]==0){
                    set<int> st;
                    int s=1;
                    for (int k=0;k<4;k++){
                        int nrow=i+dr[k];
                        int ncol=j+dc[k];
                        if (nrow<0 || ncol<0 || nrow>=n || ncol>= n || grid[nrow][ncol]==0) continue;
                        int p=dS.findUParent(nrow*n+ncol);
                        if (st.find(p)==st.end()){
                            st.insert(p);
                            s+=dS.sizeOfUnit(p);
                        }
                    }
                    largest=max(largest,s);
                }
            }
        }
        if (oneExists==true && largest==0) return n*n;
        return largest;
    }
};
