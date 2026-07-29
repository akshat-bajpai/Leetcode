class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for (int i=0;i<nums.size();i++){
            pq.push({nums[i],i});
        } 
        while (k--){
            auto top=pq.top();
            pq.pop();
            int index=top.second;
            int num=top.first;
            nums[index]=num*multiplier;
            pq.push({nums[index],index});
        }
        return nums;
    }
};
