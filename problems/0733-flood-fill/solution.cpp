class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc]==color) return image;
        int dr[]={1,-1,0,0};
        int dc[]={0,0,1,-1};
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int ogColor=image[sr][sc];
        image[sr][sc]=color;
        while (!q.empty()){
            auto node=q.front();
            q.pop();
            for (int i=0;i<4;i++){
                int nrow=node.first+dr[i];
                int ncol=node.second+dc[i];
                if (nrow>=0 && ncol>=0 && nrow<image.size() && ncol<image[0].size() && image[nrow][ncol]==ogColor){
                    q.push({nrow,ncol});
                    image[nrow][ncol]=color;
                }
            }
        }
        return image;
    }
};
