class Twitter {
    int time = 0;

    // user -> people they follow
    unordered_map<int, unordered_set<int>> following;

    // user -> list of {time, tweetId}
    unordered_map<int, vector<pair<int, int>>> tweets;

public:
    Twitter() {}

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        vector<pair<int, int>> allTweets;

        // Add user's own tweets
        for (auto tweet : tweets[userId]) {
            allTweets.push_back(tweet);
        }

        // Add tweets of followed users
        for (int followee : following[userId]) {
            for (auto tweet : tweets[followee]) {
                allTweets.push_back(tweet);
            }
        }

        // Sort from newest to oldest
        sort(allTweets.begin(), allTweets.end(),
             [](const pair<int, int>& a, const pair<int, int>& b) {
                 return a.first > b.first;
             });

        vector<int> result;

        for (int i = 0; i < min(10, (int)allTweets.size()); i++) {
            result.push_back(allTweets[i].second);
        }

        return result;
    }

    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};


