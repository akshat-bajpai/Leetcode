class Solution {
public:
    // static int kk;
    // static bool comp(vector<int>& a, vector<int>& b){
    //     return a[kk]>b[kk];
    // }
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        int m=score.size();
        int n=score[0].size();
        sort(score.begin(),score.end(),[&](auto &a, auto&b){
            return a[k]>b[k];
        });
        return score;
    }
};
