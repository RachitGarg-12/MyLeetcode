class MyHashMap {
public:
    vector<int> m;int len;
    MyHashMap() {
      len=1e6+1;m.resize(len,-1);  
    }
    
    void put(int key, int value) {
        m[key]=value;
    }
    
    int get(int key) {
        return m[key];
    }
    
    void remove(int key) {
        m[key]=-1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */