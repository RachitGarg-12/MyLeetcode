class Solution {
public:
    const int mod=1e9+7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>> a;
        for(int i=0;i<n;i++){
            a.push_back({efficiency[i],speed[i]});
        }
        sort(a.rbegin(),a.rend());
        // we sort our people according to efficiency , as we want to check for max efficency
        priority_queue<int,vector<int>,greater<int>> pq;
        //priority queue is used , so that when num of elements taken >k , then remove element with least speed ,because efficency is already fixed in sorting
        long speedsum=0,ans=0;
        for(auto &[e,s]:a){
            speedsum+=s;
            pq.push(s);
            if(pq.size()>k){
                speedsum-=pq.top();
                pq.pop();
            }
            ans=max(ans,speedsum*e);
        }
        return ans%mod;
    }
};