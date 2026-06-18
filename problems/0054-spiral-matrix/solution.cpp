class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int l=0,r=n-1,top=0,bottom=m-1;
        vector<int> spiral;
        while (l<=r && top<=bottom){
            if (top<=bottom){
                for (int i=l;i<=r;i++){
                spiral.push_back(matrix[top][i]);
                }
                top++;
            }
            
            if (l<=r){
                for (int i=top;i<=bottom;i++){
                    spiral.push_back(matrix[i][r]);
                }
                r--;
            }

            if (top<=bottom){
               for (int i=r;i>=l;i--){
                    spiral.push_back(matrix[bottom][i]);
                }
                bottom--; 
            }
            
            if (l<=r){
               for (int i=bottom;i>=top;i--){
                    spiral.push_back(matrix[i][l]);
                }
                l++; 
            }
            
        }

        return spiral;
    }
};
