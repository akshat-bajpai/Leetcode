class DisjointSet {
    vector<int> parent, size;

public:
    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findUParent(int node) {
        if (parent[node] == node)
            return node;

        return parent[node] = findUParent(parent[node]);
    }

    void unionBySize(int u, int v) {
        u = findUParent(u);
        v = findUParent(v);

        if (u == v)
            return;

        if (size[u] < size[v])
            swap(u, v);

        parent[v] = u;
        size[u] += size[v];
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {

        int maxRow = 0;
        int maxCol = 0;

        for (auto &stone : stones) {
            maxRow = max(maxRow, stone[0]);
            maxCol = max(maxCol, stone[1]);
        }

        int totalNodes = maxRow + maxCol + 2;

        DisjointSet ds(totalNodes);

        unordered_set<int> usedNodes;

        for (auto &stone : stones) {

            int rowNode = stone[0];
            int colNode = stone[1] + maxRow + 1;

            ds.unionBySize(rowNode, colNode);

            usedNodes.insert(rowNode);
            usedNodes.insert(colNode);
        }

        int components = 0;

        for (int node : usedNodes) {
            if (ds.findUParent(node) == node)
                components++;
        }

        return stones.size() - components;
    }
};
