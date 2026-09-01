class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m=classroom.size();
        int n=classroom[0].size();

        int sx=0,sy=0;
        int litterCount=0;
        vector<vector<int>> id(m, vector<int>(n, 0));
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (classroom[i][j]=='S') {
                    sx=i;
                    sy=j;
                }
                if (classroom[i][j]=='L') {
                    id[i][j]=(1<<litterCount);
                    litterCount++;
                }
            }
        }
        int totalMasks=1<<litterCount;
        vector<vector<vector<int>>> best(
            m,
            vector<vector<int>>(n, vector<int>(totalMasks, -1))
        );
        struct State {
            int x;
            int y;
            int mask;
            int energy;
            int moves;
        };
        queue<State> q;
        best[sx][sy][0] = energy;
        q.push({sx, sy, 0, energy, 0});
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        while (!q.empty()) {
            State curr = q.front();
            q.pop();
            if (curr.mask == totalMasks - 1) {
                return curr.moves;
            }
            if (curr.energy == 0) {
                continue;
            }
            for (int d = 0; d < 4; d++) {
                int nx = curr.x + dx[d];
                int ny = curr.y + dy[d];
                if (nx < 0 || nx >= m ||
                    ny < 0 || ny >= n ||
                    classroom[nx][ny] == 'X') {
                    continue;
                }
                int newEnergy;
                if (classroom[nx][ny] == 'R') {
                    newEnergy = energy;
                } else {
                    newEnergy = curr.energy - 1;
                }
                int newMask = curr.mask | id[nx][ny];
                if (newEnergy > best[nx][ny][newMask]) {
                    best[nx][ny][newMask] = newEnergy;
                    q.push({
                        nx,
                        ny,
                        newMask,
                        newEnergy,
                        curr.moves + 1
                    });
                }
            }
        }
        return -1;
    }
};
