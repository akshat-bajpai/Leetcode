class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,+1,-1};
        int rotten=0;
        int total=0;
        queue<pair<int,int>> q;
        for (int i=0;i<grid.size();i++){
            for (int j=0;j<grid[0].size();j++){
                if (grid[i][j]==2){
                    q.push({i,j});
                    rotten++;
                    total++;
                }else if (grid[i][j]==1){
                    total++;
                }
            }
        }
        int minutes=0;

        while (!q.empty()){
            int s=q.size();
            for (int i=0;i<s;i++){
                pair<int,int> f=q.front();
                q.pop();
                for (int i=0;i<4;i++){
                    int x=f.first+dx[i];
                    int y=f.second+dy[i];
                    if (x<0 || y<0 ||x>=grid.size() || y>=grid[0].size() || grid[x][y]!=1) continue;
                    q.push({x,y});
                    grid[x][y]=2;
                    rotten++;
                }
            }
            if (!q.empty()) minutes++;
        }
        if (rotten==total) return minutes;
        return -1;
    }
};
