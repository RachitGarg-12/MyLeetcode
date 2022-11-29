class RandomizedSet {
unordered_map<int,int> vals;
    vector<int>            idxs;

public:
    RandomizedSet() {}
    
    bool insert(int val) 
    {
        if (vals.count(val)) return false;
        vals[val] = idxs.size();
        idxs.push_back(val);
        return true;
    }
    
    bool remove(int val)
    {
        if (!vals.count(val)) return false;
        
        int lst = idxs.back();
        int pos = vals[val];
        
        vals[lst] = pos;
        idxs[pos] = lst;
        
        vals.erase(val);
        idxs.pop_back();
        
        return true;
    }
    
    int getRandom() 
    {
        return idxs[rand() % idxs.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */