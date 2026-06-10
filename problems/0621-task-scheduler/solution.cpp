class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mpp;
        for (int i=0;i<tasks.size();i++){
            if (mpp.find(tasks[i])==mpp.end()){
                mpp[tasks[i]]=1;
            }else{
                mpp[tasks[i]]++;
            }
        }
        priority_queue<int> pq;
        for (auto it : mpp){
            pq.push(it.second);
        }
        int time=0;
        while (!pq.empty()){
            vector<int> temp;
            for (int i=0;i<=n;i++){
                if (!pq.empty()){
                    int top=pq.top();
                    top--;
                    temp.push_back(top);
                    pq.pop();
                }
            }
            for (int i=0;i<temp.size();i++){
                if (temp[i]!=0){
                    pq.push(temp[i]);
                }  
            }
            if (pq.empty()){
                time+=temp.size();
            }else{
                time+=n+1;
            }
        }
        return time;
    }
};
