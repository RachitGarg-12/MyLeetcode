class Solution {
public:
    int maxDistance(vector<vector<int>>& a) {
        int n=a.size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis=a;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==1){q.push({i,j});}
            }
        }
        if(q.empty() || q.size()==n*n){return -1;}
        int dist=-1;
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                 auto [x,y]=q.front();
                 q.pop();                 
                for (auto [dx, dy] : dirs) {
                    int i = x + dx, j = y + dy;
                    if (i >= 0 && i < n && j >= 0 && j < n && vis[i][j] == 0) {
                        vis[i][j] = 1;
                        q.push({i, j});
                    }
                }
            }
            dist++;
        }
        return dist;
    }
};