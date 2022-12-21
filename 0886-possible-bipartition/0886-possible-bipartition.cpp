class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& d) {
        vector<vector<int>>adj(n+1);
        for(int i=0;i<d.size();i++){
            adj[d[i][0]-1].push_back(d[i][1]-1);
            adj[d[i][1]-1].push_back(d[i][0]-1);
        }
        vector<int>color(n+1,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                queue<int>q;
                q.push(i);
                color[i]=1;
                while(!q.empty()){
                    int x=q.front();
                    q.pop();
                    for(auto i:adj[x]){
                        if(color[i]==color[x])
                            return false;
                        else if(color[i]==-1){
                            color[i]=1-color[x];
                            q.push(i);
                        }
                    }
                }
            } 
        }
        return true;
    }
};