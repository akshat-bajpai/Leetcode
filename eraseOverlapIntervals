class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b){
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        if (intervals.size()==0) return 0;
        vector<int> temp;
        int n=intervals.size();
        int ans=0;
        temp=intervals[0];

        for (int i=1;i<n;i++){
            if (temp[1]>intervals[i][0]){
                ans++;
            }else{
                temp=intervals[i];
            }
        }
        return ans;
    }
};
