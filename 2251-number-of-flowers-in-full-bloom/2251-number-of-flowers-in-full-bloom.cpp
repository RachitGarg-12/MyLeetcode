class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        vector<int> start, end;
        
        for (auto& f : flowers){
            start.push_back(f[0]);
            end.push_back(f[1]);
        }
            
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        vector<int> res;
        
        for (int p : persons) {
            int started = upper_bound(start.begin(), start.end(), p) - start.begin();
            int ended = lower_bound(end.begin(), end.end(), p) - end.begin();
            res.push_back(started - ended);
        }
        
        return res;        
    }
};