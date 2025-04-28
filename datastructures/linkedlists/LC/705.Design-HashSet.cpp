class MyHashSet
{
    vector<bool> lookup;

public:
    MyHashSet()
    {
        lookup.resize(1000001, false);
    }

    void add(int key)
    {
        lookup[key] = true;
    }

    void remove(int key)
    {
        lookup[key] = false;
    }

    bool contains(int key)
    {
        return lookup[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */