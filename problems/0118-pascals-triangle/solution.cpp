class Solution {
public:
    vector<vector<int>> generate(int numRows) {
/*
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
1 5 10 10 5 1
1 6 15 20 15 6 1 */
        vector<vector<int>> ans;
        for (int i=0;i<numRows;i++){
            if (i==0){
                ans.push_back({1});
            }
            else{
                vector<int> row;
                for (int j=0;j<=i;j++){
                    if (j==0 || j==i){
                        row.push_back(1);
                    }
                    else{
                        row.push_back(ans[i-1][j-1]+ans[i-1][j]);
                    }
                }
                ans.push_back(row);
            }
        }
        return ans;
    }
};
