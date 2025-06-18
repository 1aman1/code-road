class MyHashMap
{
    vector<int> lookup;

public:
    MyHashMap()
    {
        lookup.resize(1000001, -1);
    }

    void put(int key, int value)
    {
        lookup[key] = value;
    }

    int get(int key)
    {
        return lookup[key];
    }

    void remove(int key)
    {
        lookup[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */