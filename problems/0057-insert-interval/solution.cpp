class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n=intervals.size();
        vector<vector<int>> ans;
        if (intervals.size()==0){
            ans.push_back(newInterval);
            return ans;
        } 
        int i=0;

        while (i<n && intervals[i][1]<newInterval[0]){
            ans.push_back(intervals[i]);
            i++;
        }
        if (i == n) {
            ans.push_back(newInterval);
            return ans;
        }

        vector<int> temp=newInterval;

        while(i<n && temp[1]>=intervals[i][0]){
            temp[0]=min(temp[0],intervals[i][0]);
            temp[1]=max(temp[1],intervals[i][1]);
            i++;
        }
        ans.push_back(temp);

        while (i<n){
            ans.push_back(intervals[i]);    
            i++;
        }
        return ans;
    }
};
