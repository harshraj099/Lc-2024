class Twitter {
public:
    unordered_map<int,set<int>>followers;  // a list of unique followers is made 
    unordered_map<int,vector<pair<int,int>>>tweetmap; // a list of tweets agaings of the userIds
    int time;  // to keep the check of recent tweets
    Twitter() {
    }
    
    void postTweet(int userId, int tweetId) {
        tweetmap[userId].push_back({++time,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>>pq;
        // include ur own tweet
        for(auto it:tweetmap[userId]){
            pq.push(it);
        }

        // include ur followers tweets
        for(auto flws:followers[userId]){
            for(auto tws:tweetmap[flws]){
            pq.push(tws);
        }
        }
        vector<int>res;
        int cnt=10;
        while(!pq.empty() && cnt>0){
            res.push_back(pq.top().second);
            pq.pop();
            cnt--;
        }

        return res;
    }
    
    void follow(int followerId, int followeeId) {
      if(followerId!=followeeId)  followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId!=followeeId)   followers[followerId].erase(followeeId);
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