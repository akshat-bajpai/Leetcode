class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        int n=points.size();
        vector<int> ans;
        for (int i=0;i<queries.size();i++){
            int xi=queries[i][0];
            int yi=queries[i][1];
            int ri=queries[i][2];
            int c=0;
            for (int point=0;point<n;point++){
                int x=points[point][0];
                int y=points[point][1];
                if (pow(xi-x,2)+pow(yi-y,2)<=pow(ri,2)) c++;
            }
            ans.push_back(c);
        }
        return ans;
    }
};
