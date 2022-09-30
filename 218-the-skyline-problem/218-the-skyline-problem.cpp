class Solution {
public:
    static bool compare(vector<int>& a, vector<int>& b){
        if(a[0]==b[0]) return a[1]<b[1];
        return a[0]<b[0];
    }
    
    vector<vector<int>> getResult(vector<vector<int>>& pos, vector<vector<int>> &result, priority_queue<int>& pq, int mv){
        int n = pos.size();
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++){
            int v = pos[i][1];
            if(v>=0){
                mp[v]++;
                while(mp[pq.top()]>0){
                    mp[pq.top()]--;
                    pq.pop();
                }
                if(pq.empty()){
                    if(i==n-1 || pos[i+1][0]!=pos[i][0]){
                        result.push_back({pos[i][0],0});
                        mv = 0;
                    }
                }
                else if(pq.top()<mv){
                    mv = pq.top();
                    result.push_back({pos[i][0], mv});
                }
            }
            else{
                pq.push(abs(v));
                if(pq.top()>mv){
                    mv = pq.top();
                    result.push_back({pos[i][0], mv});                    
                }
            }
        }
        return result;
    }
    
    vector<vector<int>> getSkyline(vector<vector<int>>& build) {
        vector<vector<int>> pos, result;
        int n = build.size();
        for(int i=0; i<n; i++){
            pos.push_back({build[i][0],-build[i][2]});
            pos.push_back({build[i][1],build[i][2]});
        }
        sort(pos.begin(), pos.end(), compare);
        priority_queue<int> pq;
        int mv = 0;
        pq.push(0);
        result = getResult(pos, result, pq, mv);
        return result;
    }
};