class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> minCost(rows, vector<int>(cols, -1));
        vector<pair<int, int>> directions = {
            {0, 1}, {1, 0}, {-1, 0}, {0, -1}
        };
        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<>
        > pq;
        pq.push({grid[0][0], 0, 0});
        while (!pq.empty()) {
            auto [cost, row, col] = pq.top();
            pq.pop();
            if (minCost[row][col] != -1)
                continue;
            minCost[row][col] = cost;
            for (auto [dx, dy] : directions) {
                int newRow = row + dx;
                int newCol = col + dy;
                if (newRow < 0 || newRow >= rows ||
                    newCol < 0 || newCol >= cols)
                    continue;
                if (minCost[newRow][newCol] != -1)
                    continue;
                int newCost = cost + grid[newRow][newCol];
                pq.push({newCost, newRow, newCol});
            }
        }
        return minCost[rows - 1][cols - 1] < health;
    }
};
