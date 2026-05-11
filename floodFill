class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc]==color) return image;
        queue<pair<int,int>>q;
        vector<int> dx={1,-1,0,0};
        vector<int> dy={0,0,1,-1};
        q.push({sr,sc});
        int ogColor=image[sr][sc];
        while (!q.empty()){
            pair<int,int> rc=q.front();
            q.pop();
            image[rc.first][rc.second]=color;
            for (int i=0;i<4;i++){
                int nrow=rc.first+dx[i];
                int ncol=rc.second+dy[i];
                if (nrow<0 || ncol<0 || nrow>=image.size() ||ncol>=image[0].size() || image[nrow][ncol]!=ogColor) continue;
                q.push({nrow,ncol});
            }
        }
        return image;
    }
};
