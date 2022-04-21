class MyHashSet {
    
public:
    vector<list<int>> m;
    int size;
    MyHashSet() {
        size = 100;
        m.resize(size);
    }
    int hash(int key)
    {
        return (key%size);
    }
    list<int>::iterator search(int key)
    {
        int i=hash(key);
        return find(m[i].begin(),m[i].end(),key);
    }
    void add(int key) {
        int i=hash(key);
        if(contains(key))
            return;
        m[i].push_back(key);
    }
    
    void remove(int key) {
         int i=hash(key);
        if(!contains(key))
            return;
        m[i].erase(search(key));
    }
    
    bool contains(int key) {
        int i=hash(key);
        if(search(key)==m[i].end())
            return false;
        else
            return true;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */