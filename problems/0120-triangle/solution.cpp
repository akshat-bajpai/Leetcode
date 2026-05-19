class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<int> prev(n,0);
        for (int i=0;i<n;i++){
            vector<int> temp(n,0);
            for (int j=0;j<=i;j++){
                if (i==0 && j==0){
                    temp[j]=triangle[0][0];
                    prev=temp;
                    continue;
                }
                int l=INT_MAX, r=INT_MAX;
                if (j!=i) l=prev[j];
                if (j-1>=0) r=prev[j-1];
                temp[j]=min(l,r)+triangle[i][j];
            }
            prev=temp;
        }
        int answer=INT_MAX;
        for (int i=0;i<n;i++){
            answer=min(answer,prev[i]);
        }
        return answer;
    }
};
