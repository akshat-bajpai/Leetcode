class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<pair<int,int>> arr;
        int n=nums.size();
        for (int i=0;i<nums.size();i++){
            arr.push_back({nums[i],i});
        }
        sort(arr.begin(),arr.end());
        int start=0;
        while(start<n){
            int end=start;
            while (end+1<n && arr[end+1].first<=limit+arr[end].first) end++;
            vector<int> indices;
            for (int i=start;i<=end;i++){
                indices.push_back(arr[i].second);
            }
            sort(indices.begin(),indices.end());
            for (int i=start;i<=end;i++){
                nums[indices[i-start]]=arr[i].first;
            }
            start=end+1;
        }
        return nums;
    }
};
