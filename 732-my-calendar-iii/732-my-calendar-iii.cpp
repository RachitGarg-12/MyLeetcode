class MyCalendarThree {
public:
    map<int,int>mp;
    int maxcount;
    MyCalendarThree() {
        maxcount=0;
    }
    int book(int start, int end) {
        mp[start]++;
        mp[end]--;
        int count=0;
        for(auto&it:mp){
            count+=it.second;
            maxcount=max(maxcount,count);
        }
        return maxcount;
    }
    // video reference
    
};


/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */