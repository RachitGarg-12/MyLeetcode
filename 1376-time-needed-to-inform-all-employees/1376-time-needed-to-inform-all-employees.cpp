class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n);
        int root=0;
        for(int i=0;i<n;i++){
            if(manager[i]==-1){root=i;continue;}
            adj[manager[i]].push_back(i);
        }
        int ans=0;
        queue<pair<int,int>> q;
        q.push({root,0});
        while(!q.empty()){
            int l=q.size();
            while(l--){
                int cur=q.front().first;
                int time=q.front().second+informTime[cur];
                ans=max(ans,time);
                q.pop();
                for(auto i:adj[cur]){
                    q.push({i,time});
                }
            }
        }
        return ans;
    }
};