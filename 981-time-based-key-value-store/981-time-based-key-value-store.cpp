class TimeMap {
public:
    unordered_map<string,map<int,string>> m;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        
        m[key][timestamp]=value;
    }
    
    string get(string key, int timestamp) {
  
        //upper bound give just greater time than timestamp
        auto it=m[key].upper_bound(timestamp);  
        
        //if m[key].begin() is the upper bound that means every time present in m[key] is greater than 'timestamp'
        if(it==m[key].begin())  
            return "";
        
        --it;  // as 'it' is just greater than actual 'timestamp' we need <= so --it;
        return it->second;    // it.first is the 'time' it.second is the 'value'        
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */