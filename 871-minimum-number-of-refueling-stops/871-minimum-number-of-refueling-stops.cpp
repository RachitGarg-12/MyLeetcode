class Solution {
public:
   int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
    
    int n=stations.size();
    int currFuel=startFuel, i=0;     //i -> starting index
    int res=0;
    
    priority_queue<int> pq;      //max heap -> it will store the max distance travelled from a petrol pump
    
    while(currFuel < target){
        
        while(i<n && currFuel >= stations[i][0]){    //if at a particular station, currFuel>= position of pump
            pq.push(stations[i][1]);                 // i.e. currFuel >= stations[i][0]
            i++;                                     //then push it's fuel into max heap
        }
        
        if(pq.empty()) return -1;          //if pq is empty just return -1
        
        currFuel += pq.top();              //update currFuel by adding pq.top()
        pq.pop();
        
        res++;                             //increment res
    }
    return res;
}
};