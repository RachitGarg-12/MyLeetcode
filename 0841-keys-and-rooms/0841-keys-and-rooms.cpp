class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        map<int,int> m;
        int n=rooms.size();
        vector<bool> vis(n,false);
        vis[0]=true;
        queue<int> q;
        for(auto i:rooms[0]){q.push(i);}
        while(!q.empty()){
            int cur=q.front();q.pop();
            if(!vis[cur]){
                vis[cur]=true;
                for(auto i:rooms[cur]){
                    q.push(i);
                }
            }  
        }
        for(auto i:vis){if(i==false)return false;}
        return true;
    }
};