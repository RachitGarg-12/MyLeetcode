class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int n=nums.size();
        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
        }
        while(k--){
            int x=pq.top().first;
            int ind=pq.top().second;
            pq.pop();
            x*=multiplier;
            pq.push({x,ind});
        }
        while(!pq.empty()){
            int x=pq.top().first;
            int ind=pq.top().second;
            pq.pop();
            nums[ind]=x;
        }
        return nums;
    }
};