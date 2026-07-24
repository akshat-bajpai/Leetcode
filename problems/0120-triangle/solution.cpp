class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<int> next(n,0);
        for (int i=0;i<n;i++){
            next[i]=triangle[n-1][i];
        }
        for (int i=n-2;i>=0;i--){
            vector<int> cur(n,0);
            for (int j=0;j<=i;j++){
                int d=triangle[i][j]+next[j];
                int dg=triangle[i][j]+next[j+1];
                cur[j]=min(d,dg);
            }
            next=cur;
        }
        return next[0];
    }
};
