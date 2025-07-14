
struct Pair
{
    int key;
    int value;

    Pair(int Key, int Value) : key(Key), value(Value) {}
};

class LRUCache
{
    int capacity;
    std::list<Pair> kVcontainer;
    std::unordered_map<int, std::list<Pair>::iterator> keyItrCache;

public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key)
    {
        if (!keyItrCache.count(key))
            return -1;

        const auto &itrToValue = keyItrCache.at(key);
        kVcontainer.splice(kVcontainer.begin(), kVcontainer, itrToValue);
        return kVcontainer.front().value;
    }

    void put(int key, int value)
    {
        if (keyItrCache.count(key))
        {
            const auto &itrToValue = keyItrCache.at(key);
            kVcontainer.splice(kVcontainer.begin(), kVcontainer, itrToValue);
            itrToValue->value = value;

            return;
        }

        if (capacity == kVcontainer.size())
        {
            keyItrCache.erase(kVcontainer.back().key);
            kVcontainer.pop_back();
        }

        kVcontainer.emplace_front(key, value);
        keyItrCache[key] = kVcontainer.begin();
    }
};