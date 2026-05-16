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
    int findUPar(int node){
        if (parent[node]==node) return node;
        return parent[node]=findUPar(parent[node]);
    }
    void unionBySize(int u, int v){
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        DisjointSet dS(n);
        unordered_map<string,int> mapMailToNode;
        for (int i=0;i<n;i++){
            for (int j=1;j<accounts[i].size();j++){
                string mail=accounts[i][j];
                if (mapMailToNode.find(mail)==mapMailToNode.end()){
                    mapMailToNode[mail]=i;
                }else{
                    dS.unionBySize(i,mapMailToNode[mail]);
                }
            }
        }

        vector<vector<string>> mails(n);

        for (auto it : mapMailToNode){
            string mail=it.first;
            int node=it.second;
            int parent=dS.findUPar(node);
            mails[parent].push_back(mail);
        }

        for (int i=0;i<mails.size();i++){
            sort(mails[i].begin(),mails[i].end());
        }

        vector<vector<string>> answer;

        for (int i=0;i<mails.size();i++){
            if (mails[i].size()!=0){
                vector<string> temp;
                temp.push_back(accounts[i][0]);
                for (int j=0;j<mails[i].size();j++){
                    temp.push_back(mails[i][j]);
                }
                answer.push_back(temp);
            }
        }
        return answer;
    }
};
