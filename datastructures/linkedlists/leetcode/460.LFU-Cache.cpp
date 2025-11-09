class LFUCache
{
    int capacity;
    int minFreq;

    using ListIter = std::list<int>::iterator;

    // key -> {value, frequency}
    std::unordered_map<int, std::pair<int, int>> keyToValueFreq;

    // frequency -> list of keys (in order of recency)
    std::unordered_map<int, std::list<int>> freqToKeys;

    // key -> iterator in its frequency list
    std::unordered_map<int, ListIter> keyToIterator;

public:
    LFUCache(int capacity) : capacity(capacity), minFreq(0) {}

    int get(int key)
    {
        if (!keyToValueFreq.count(key))
            return -1;

        auto [value, freq] = keyToValueFreq[key];

        // remove key from current frequency list
        freqToKeys[freq].erase(keyToIterator[key]);

        // if no more keys with this frequency
        if (freqToKeys[freq].empty())
        {
            freqToKeys.erase(freq);
            if (minFreq == freq)
                ++minFreq;
        }

        // move key to higher frequency bucket
        freqToKeys[freq + 1].push_front(key);
        keyToIterator[key] = freqToKeys[freq + 1].begin();
        keyToValueFreq[key] = {value, freq + 1};

        return value;
    }

    void put(int key, int value)
    {
        if (capacity == 0)
            return;

        // If key exists, just update its value and frequency
        if (keyToValueFreq.count(key))
        {
            keyToValueFreq[key].first = value;
            get(key); // reuse get() to update frequency
            return;
        }

        // Eviction if at capacity
        if (keyToValueFreq.size() == capacity)
        {
            int keyToEvict = freqToKeys[minFreq].back();
            freqToKeys[minFreq].pop_back();

            if (freqToKeys[minFreq].empty())
                freqToKeys.erase(minFreq);

            keyToValueFreq.erase(keyToEvict);
            keyToIterator.erase(keyToEvict);
        }

        // Insert new key with freq = 1
        minFreq = 1;
        freqToKeys[1].push_front(key);
        keyToIterator[key] = freqToKeys[1].begin();
        keyToValueFreq[key] = {value, 1};
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */