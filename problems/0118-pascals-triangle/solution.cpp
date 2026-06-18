class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal={{1}};
        for (int row=1;row<numRows;row++){
            vector<int> prevRow=pascal.back();
            vector<int> nextRow(prevRow.size()+1);
            for (int i=0;i<nextRow.size();i++){
                if (i!=0 && i!=nextRow.size()-1){
                    nextRow[i]=prevRow[i-1]+prevRow[i];
                }else{
                    nextRow[i]=1;
                }
            }
            pascal.push_back(nextRow);
        }
        return pascal;
    }
};
