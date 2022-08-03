class MyCalendar {
public:
    vector<pair<int,int>> time;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for (auto i : time)
            if (max(i.first, start) < min(end, i.second)) return false;
        time.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */