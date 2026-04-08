class Solution {
public:
int leastInterval(vector<char>& tasks, int n) {
    unordered_map<char, int> freq;
    for (char t : tasks) freq[t]++;

    priority_queue<int> pq;
    for (auto &p : freq)
        pq.push(p.second);

    int time = 0;

    while (!pq.empty()) {
        vector<int> temp;
        int cycle = n + 1;
        while (cycle-- && !pq.empty()) {
            int cnt = pq.top(); pq.pop();
            if (cnt - 1 > 0)
                temp.push_back(cnt - 1);
            time++;
        }
        for (int x : temp)
            pq.push(x);

        if (pq.empty()) break;
        time += cycle + 1;
    }
    return time;
}
};
