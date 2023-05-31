class UndergroundSystem {
public:
    unordered_map<int,pair<string,int>> pass;
    map<pair<string,string>,vector<int>> m;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        pass[id]={stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string start=pass[id].first;
        int ts=pass[id].second;
        m[{start,stationName}].push_back({t-ts});
    }
    
    double getAverageTime(string startStation, string endStation) {
        double sum=0;
        int l=m[{startStation,endStation}].size();
        for(auto i:m[{startStation,endStation}]){
            sum+=i;
        }
        sum/=l;
        return sum;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */