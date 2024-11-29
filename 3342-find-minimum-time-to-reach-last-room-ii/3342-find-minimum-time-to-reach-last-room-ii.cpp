class Solution {
public:
    int minTimeToReach(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> time(m + 1, vector<int>(n + 1, INT_MAX));
        vector<vector<int>> vis(m + 1, vector<int>(n + 1, 0));

        priority_queue<vector<int>, 
                        vector<vector<int>>, 
                        greater<vector<int>>> pq;
        pq.push({0,0, 0,0});  // Start from the top-left corner

        int x[] = {0, 0, 1, -1};
        int y[] = {1, -1, 0, 0};
        
        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();

            int t = p[0];
            int curx = p[1];
            int cury = p[2];
            int alt=p[3];

            // Return time if we reach the bottom-right corner
            if (curx == m - 1 && cury == n - 1) {
                return t;
            }

            if (vis[curx][cury]) continue;
            vis[curx][cury] = 1;

            for (int i = 0; i < 4; i++) {
                int newx = curx + x[i];
                int newy = cury + y[i];

                if (newx >= 0 && newx < m && newy >= 0 && newy < n) {
                    int needtime =(alt==0)? t + 1 : t + 2;

                    // Adjust time based on grid values
                    if (grid[newx][newy] > t ) {
                        needtime = (alt==0)?grid[newx][newy] + 1:grid[newx][newy] + 2;
                    }

                    if (needtime < time[newx][newy]) {
                        time[newx][newy] = needtime;
                        pq.push({needtime,newx, newy,!alt});
                    }
                }
            }
        }

        return -1;        
    }
};