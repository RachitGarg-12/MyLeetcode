class SummaryRanges {
public:
    set<int> a;
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        a.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> intervals;
        int start=*a.begin(),end=*a.begin();
        
        for(auto it=++a.begin();it!=a.end();it++){
            if(*it-end==1){end=*it;}
            else{
                intervals.push_back({start,end});
                start=*it;
                end=*it;
            }
        }
        intervals.push_back({start,end});
        return intervals;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */