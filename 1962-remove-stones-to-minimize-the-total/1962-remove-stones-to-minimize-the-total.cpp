class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        int total=0;
        for(auto i:piles){
            pq.push(i);
            total += i;
        }
        int remove=0;
        while(!pq.empty() && k--){
            int mx=pq.top();pq.pop();
            total -= mx/2;
            int left= mx- mx/2;
            if(left>0){pq.push(left);}
        }
        cout<<remove<<endl;
        return total;
    }
};