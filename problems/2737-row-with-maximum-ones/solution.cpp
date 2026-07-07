class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int rowNo=-1;
        int max1s=-1;
        for (int i=0;i<mat.size();i++){
            int ones=0;
            for (int j=0;j<mat[0].size();j++){
                if (mat[i][j]==1) ones++;
            }
            if (ones>max1s){
                max1s=ones;
                rowNo=i;
            }
        }
        return {rowNo,max1s};
    }
};
