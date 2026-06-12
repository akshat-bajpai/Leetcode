class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mpp;
        for (int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        int unique=0;
        for (auto it : mpp){
            if (unique!=k){
                pq.push({it.second, it.first});
                unique++;
                continue;
            }
            if (pq.top().first<it.second){
                pq.pop();
                pq.push({it.second, it.first});
            }           
        }
        vector<int> ans;
        while (!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
