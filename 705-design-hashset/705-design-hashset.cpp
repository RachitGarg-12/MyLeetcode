class MyHashSet {
public:
    vector<list<int>> m;
    int len;
    MyHashSet() {
        len=1e6+1;m.resize(len);
    }
    int hash(int key){
        return key%len;
    }
    list<int> :: iterator search(int key){
        int i=hash(key);
        return find(m[i].begin(),m[i].end(),key);  //if not present it will give m[i].end()
    }
    void add(int key) {
       if(contains(key)){return;}
        int i=hash(key);
        m[i].push_back(key);
    }
    
    void remove(int key) {
        if(contains(key)){
        int i=hash(key);
        m[i].erase(search(key));}
    }
    
    bool contains(int key) {
        int i=hash(key);
        if(search(key)!=m[i].end()){return true;}
        else{return false;}
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */