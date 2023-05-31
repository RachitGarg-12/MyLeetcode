class UndergroundSystem {
public:
    unordered_map<int,pair<string,int>> pass;
    unordered_map<string,pair<int,int>> m;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        pass[id]={stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string start=pass[id].first;
        int ts=pass[id].second;
        string concat=start+','+stationName;
        m[concat].first+=t-ts;
        m[concat].second++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string concat=startStation+','+endStation;
        double sum=m[concat].first;
        double l=m[concat].second;
        return sum/l;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */