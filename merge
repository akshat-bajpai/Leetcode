class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        vector<vector<int>> ans;

        vector<int> temp;
        for (int i=0;i<n;i++){
            if (temp.size()==0){
                temp.push_back(intervals[i][0]);
                temp.push_back(intervals[i][1]);
            }else{
                if (temp[1]>=intervals[i][0]){
                    temp[1]=max(intervals[i][1],temp[1]);
                }else{
                    ans.push_back(temp);
                    temp[0]=intervals[i][0];
                    temp[1]=intervals[i][1];
                }
            }
        }
        ans.push_back(temp);
        return ans;
    }
};
