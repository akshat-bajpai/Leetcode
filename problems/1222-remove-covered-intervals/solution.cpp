class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            if (a[0] == b[0])
                return a[1] > b[1];  
            return a[0] < b[0];
            });
        vector<int> temp=intervals[0];
        int remaining=1;
        for (int i=1;i<intervals.size();i++){
            if (intervals[i][0]>=temp[0] && temp[1]>=intervals[i][1]){
                continue;
            }else{
                temp=intervals[i];
                remaining++;
            }
        }
        return remaining;
    }
};
