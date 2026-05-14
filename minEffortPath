class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int dr[]={1,-1,0,0};
        int dc[]={0,0,1,-1};
        int low=INT_MAX;
        int high=INT_MIN;
        for (int i=0;i<heights.size();i++){
            for (int j=0;j<heights[0].size();j++){
                if (heights[i][j]<low){
                    low=heights[i][j];
                }
                if (heights[i][j]>high){
                    high=heights[i][j];
                }
            }
        }
        high=high-low;
        low=0;
        int mid;
        int value;
        while (low<=high){
            mid=low+(high-low)/2;
            vector<vector<int>>vis(heights.size(),vector<int>(heights[0].size(),0));
            vis[0][0]=1;
            queue<pair<int,int>>q;
            q.push({0,0});
            while (!q.empty()){
                int r=q.front().first;
                int c=q.front().second;
                q.pop();
                for (int i=0;i<4;i++){
                    int nrow=r+dr[i];
                    int ncol=c+dc[i];
                    if (nrow<0 || ncol<0 || nrow>=heights.size() || ncol>=heights[0].size() || vis[nrow][ncol]==1 || abs(heights[nrow][ncol]-heights[r][c])>mid) continue;
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
            if (vis[heights.size()-1][heights[0].size()-1]==1){
                value=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return value;
    }
};
