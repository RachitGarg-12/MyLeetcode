class Solution {
public:
    long long findScore(vector<int>& nums) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int n=nums.size();
        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
        }
        vector<bool> vis(n,false);
        long long ans=0;
        while(!pq.empty()){
            long long cur=pq.top().first;
            int ind=pq.top().second;
            pq.pop();
            if(!vis[ind]){
                ans+=cur;
                vis[ind]=true;
                if(ind-1>=0){
                    vis[ind-1]=true;
                }
                if(ind+1<n){
                    vis[ind+1]=true;
                }
            }
            
        }
        return ans;
    }
};