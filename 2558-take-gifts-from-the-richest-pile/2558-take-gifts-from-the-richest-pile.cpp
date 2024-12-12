class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        for(auto i:gifts){pq.push(i);}
        while(k--){
            int t=pq.top();
            pq.pop();
            pq.push(floor(sqrt(t)));
        }
        long long a=0;
        while(!pq.empty()){
            a+=pq.top();pq.pop();
        }
                    return a;        
    }
};