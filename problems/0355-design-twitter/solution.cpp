class Twitter {
public:
    map<int,vector<pair<int,int>>> tweets;
    map<int,unordered_set<int>> follows;
    int time;
    Twitter() {
        time=0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time,tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for (int i=0;i<tweets[userId].size();i++){
            pq.push(tweets[userId][i]);
            if (pq.size()>10) pq.pop();
        }
        for (auto it : follows[userId]){
            for (int i=0;i<tweets[it].size();i++){
                pq.push(tweets[it][i]);
                if (pq.size()>10) pq.pop();
            }
        }
        vector<int> feed;
        while (!pq.empty()){
            feed.push_back(pq.top().second);
            pq.pop();
        }
        reverse(feed.begin(),feed.end());
        return feed;

    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
