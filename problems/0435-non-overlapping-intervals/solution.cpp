class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b){
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans=0;

        sort(intervals.begin(),intervals.end(),comp);
        int last=INT_MIN;

        for(int i=0;i<intervals.size();i++){
            if (intervals[i][0]>=last){
                last=intervals[i][1];
            }else{
                ans++;
            }
        }
        return ans;
    }
};
