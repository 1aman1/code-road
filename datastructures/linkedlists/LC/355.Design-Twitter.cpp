class Twitter
{
    int globalTimeStamp;
    const int Top10 = 10;

    struct tweetNode
    {
        int tweetId;
        int timestamp;
        shared_ptr<tweetNode> next;

        tweetNode(int _tweetId, int _timestamp) : tweetId(_tweetId), timestamp(_timestamp), next(nullptr)
        {
        }
    };

    struct compareTweetsDefinition
    {
        bool operator()(const shared_ptr<tweetNode> &lhs, const shared_ptr<tweetNode> &rhs)
        {
            return lhs->timestamp < rhs->timestamp;
        }
    };

    using MaxHeap = priority_queue<shared_ptr<tweetNode>, vector<shared_ptr<tweetNode>>, compareTweetsDefinition>;
    unordered_map<int, shared_ptr<tweetNode>> useridToTweetlist;
    unordered_map<int, unordered_set<int>> userTofollowedUsers;

public:
    Twitter()
    {
        globalTimeStamp = 0;
    }

    void postTweet(int userId, int tweetId)
    {
        auto newTweet = make_shared<tweetNode>(tweetId, ++globalTimeStamp);
        if (useridToTweetlist.find(userId) != useridToTweetlist.end())
        {
            newTweet->next = useridToTweetlist.at(userId);
            useridToTweetlist.at(userId) = newTweet;
        }
        else
        {
            useridToTweetlist.insert({userId, newTweet});
        }
    }

    void readOwnTweets(int userId, MaxHeap &heap)
    {
        int pickTweets = Top10;
        auto readTweets = useridToTweetlist[userId];
        while (readTweets && pickTweets--)
        {
            heap.push(readTweets);
            readTweets = readTweets->next;
        }
    }

    void readFolloweesTweets(int userId, MaxHeap &heap)
    {
        if (userTofollowedUsers.count(userId))
        {
            for (int followeeId : userTofollowedUsers[userId])
            {
                int pickTweets = Top10;
                shared_ptr<tweetNode> node = useridToTweetlist[followeeId];
                while (node && pickTweets--)
                {
                    heap.push(node);
                    node = node->next;
                }
            }
        }
    }

    vector<int> top10Tweets(MaxHeap &heap)
    {
        int pickTweets = Top10;
        vector<int> result;
        shared_ptr<tweetNode> readTweet = nullptr;

        while (pickTweets-- && heap.size())
        {
            readTweet = heap.top();
            result.push_back(readTweet->tweetId);
            heap.pop();
        }

        return result;
    }

    vector<int> getNewsFeed(int userId)
    {
        MaxHeap heap;

        readOwnTweets(userId, heap);

        readFolloweesTweets(userId, heap);

        return top10Tweets(heap);
    }

    void follow(int followerId, int followeeId)
    {
        if (followerId == followeeId)
            return;
        userTofollowedUsers[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId)
    {
        if (userTofollowedUsers.count(followerId))
        {
            userTofollowedUsers[followerId].erase(followeeId);
        }
    }
};
