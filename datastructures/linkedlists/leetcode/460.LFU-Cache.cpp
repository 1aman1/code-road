class LFUCache
{
    int capacity, minFreq;
    typedef std::list<int>::iterator listIt;

    std::unordered_map<int, std::pair<int, int>> keytoValFreq;
    std::unordered_map<int, std::list<int>> freqtoKeys;
    std::unordered_map<int, listIt> keytoItr;

public:
    LFUCache(int capacity) : capacity(capacity), minFreq(0)
    {
    }

    int get(int key)
    {
        if (!keytoValFreq.count(key))
            return -1;

        auto [val, freq] = keytoValFreq.at(key);

        freqtoKeys[freq].erase(keytoItr.at(key));
        if (freqtoKeys[freq].empty())
        {
            freqtoKeys.erase(freq);
            if (minFreq == freq)
                ++minFreq;
        }

        freqtoKeys[freq + 1].push_front(key);

        keytoItr[key] = freqtoKeys[freq + 1].begin();

        keytoValFreq[key] = {val, freq + 1};

        return val;
    }

    void put(int key, int value)
    {
        if (capacity == 0)
            return;

        if (keytoValFreq.count(key))
        {
            keytoValFreq[key].first = value;

            get(key);
            return;
        }

        if (keytoValFreq.size() == capacity)
        {
            int evictionKey = freqtoKeys[minFreq].back();
            freqtoKeys[minFreq].pop_back();

            if (freqtoKeys[minFreq].empty())
            {
                freqtoKeys.erase(minFreq);
            }

            keytoItr.erase(evictionKey);
            keytoValFreq.erase(evictionKey);
        }

        keytoValFreq[key] = {value, 1};
        minFreq = 1;
        freqtoKeys[1].push_front(key);
        keytoItr[key] = freqtoKeys[1].begin();
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */