class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int k;
    KthLargest(int c, vector<int>& nums) {
        k=c;
        if (nums.size()==0) return;
        for (int i=0;i<min((int)nums.size(),k);i++){
            pq.push(nums[i]);
        }
        for (int i=k;i<nums.size();i++){
            if (pq.top()<nums[i]){
                pq.pop();
                pq.push(nums[i]);
            }
        }
    }
    
    int add(int val) {
        if (pq.size()==k){
            if(val>pq.top()){
                pq.pop();
                pq.push(val);
            }
        }else{
            pq.push(val);
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
