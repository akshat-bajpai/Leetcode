class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int dr[]={1,-1,0,0};
        int dc[]={0,0,1,-1};
        int r=heights.size();
        int c=heights[0].size();
        int low=0;
        int high=heights[0][0];
        for (int i=0;i<r;i++){
            for (int j=0;j<c;j++){
                high=max(high,heights[i][j]);
            }
        }
        int ans=-1;
        while (low<=high){
            int mid=low+(high-low)/2;
            queue<pair<int,int>> q;
            q.push({0,0});
            vector<vector<int>> vis(r,vector<int>(c,0));
            vis[0][0]=1;
            bool found=false;
            while (!q.empty()){
                auto node=q.front();
                q.pop();
                if (node.first==r-1 && node.second==c-1){
                    found=true;
                }
                for (int i=0;i<4;i++){
                    int nrow=node.first+dr[i];
                    int ncol=node.second+dc[i];
                    if (nrow>=0 && ncol>=0 && nrow<r && ncol<c && vis[nrow][ncol]==0 && abs(heights[nrow][ncol]-heights[node.first][node.second]) <= mid){
                        vis[nrow][ncol]=1;
                        q.push({nrow,ncol});
                    }
                }
            }
            if (found){
                ans=mid;high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};
