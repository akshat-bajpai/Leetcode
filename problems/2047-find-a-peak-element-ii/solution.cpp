class Solution {
public:
    int peak(vector<vector<int>>& mat,int col){
        int max=-1;
        int index=-1;
        for (int i=0;i<mat.size();i++){
            if (mat[i][col]>max){
                max=mat[i][col];
                index=i;
            }
        }
        return index;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int low=0;
        int high=mat[0].size()-1;
        while (low<=high){
            int mid=low+(high-low)/2;
            int index=peak(mat,mid);
            int left= mid-1>=0? mat[index][mid-1] : -1;
            int right=mid+1<=mat[index].size()-1?mat[index][mid+1] : -1;
            if (right<mat[index][mid] && left<mat[index][mid]) return {index,mid};
            else if (mat[index][mid]<right) low=mid+1;
            else high=mid-1;
        }
        return {-1,-1};
    }
};
