class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> adj(n);
        vector<int> indeg(n,0);
        for(auto i:relations){
            adj[i[0]-1].push_back(i[1]-1);
            indeg[i[1]-1]++;
        }
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0){q.push({i,0});}
        }
        vector<int> ctime(n,0); 
        while(!q.empty()){
            int node=q.front().first, tt=q.front().second;
            q.pop();
            tt+=time[node];
            ctime[node]=tt;
            for(auto &i:adj[node]){
                ctime[i]=max(ctime[i],tt);
                indeg[i]--;
                if(indeg[i]==0){
                  q.push({i,ctime[i]});
                }
            }
        }
        int ans=0;
        for(auto &i:ctime){
            ans=max(ans,i);
        }
        return ans;
    }
};


