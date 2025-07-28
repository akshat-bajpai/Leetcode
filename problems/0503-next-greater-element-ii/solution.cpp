class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        stack<int> st;
        map<int,int>mpp;
        for (int i=2*n-1;i>=0;i--){
            if (st.empty()){
                st.push(nums[i%n]);
                mpp[i]=-1;
            }else{
                while(!st.empty() && nums[i%n]>=st.top()){
                    st.pop();
                }
                mpp[i]=st.empty()?-1:st.top();
                st.push(nums[i%n]);
            }
        }
        vector<int>ans;
        for (int i=0;i<n;i++){
            ans.push_back(mpp[i]);
        }
        return ans;
    }
};
