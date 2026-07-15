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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,int> mpp;
        int n=accounts.size();
        DisjointSet ds(n);
        for (int i=0;i<n;i++){
            for (int j=1;j<accounts[i].size();j++){
                if (mpp.find(accounts[i][j])==mpp.end()){
                    mpp[accounts[i][j]]=i;
                }else{
                    ds.unionBySize(i,mpp[accounts[i][j]]);
                }
            }
        }
        vector<vector<string>> merged(n);
        for (auto it : mpp){
            string mail=it.first;
            int node=it.second;
            merged[ds.findUParent(node)].push_back(mail);
        }
        vector<vector<string>> ans;
        for (int i=0;i<n;i++){
            if (merged[i].size()==0) continue;
            sort(merged[i].begin(),merged[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for (auto it : merged[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
