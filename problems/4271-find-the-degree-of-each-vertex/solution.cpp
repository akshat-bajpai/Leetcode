class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n=matrix.size();
        for (int i=0;i<n;i++){
            int num=0;
            for (int j=0;j<n;j++){
                if (matrix[i][j]==1) num++;
            }
            ans.push_back(num);
        }
        return ans;
    }
};
