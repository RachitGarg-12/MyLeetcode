class SeatManager {
public:
    int last=0;
    priority_queue<int,vector<int>,greater<int>> pq;
    SeatManager(int n) {
        
    }
    
    int reserve() {
        if(pq.empty()){
            last++;
            return last;
        }
        else{
            int seat=pq.top();
            pq.pop();
            return seat;
        }
    }
    
    void unreserve(int seatNumber) {
        if(seatNumber==last){
            last--;
        }
        else{
            pq.push(seatNumber);
        }
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */