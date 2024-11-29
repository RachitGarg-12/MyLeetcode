class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Check if it's impossible to reach the destination from the start
        if (grid[0][1] > 1 && grid[1][0] > 1) return -1;

        vector<vector<int>> time(m + 1, vector<int>(n + 1, INT_MAX));
        vector<vector<int>> vis(m + 1, vector<int>(n + 1, 0));

        priority_queue<pair<int, pair<int, int>>, 
                        vector<pair<int, pair<int, int>>>, 
                        greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}});  // Start from the top-left corner

        int x[] = {0, 0, 1, -1};
        int y[] = {1, -1, 0, 0};

        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();

            int t = p.first;
            int curx = p.second.first;
            int cury = p.second.second;

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
                    int needtime = t + 1;

                    // Adjust time based on grid values
                    if (grid[newx][newy] > t + 1) {
                        int diff = grid[newx][newy] - t;
                        needtime = (diff % 2) ? grid[newx][newy] : grid[newx][newy] + 1;
                    }

                    if (needtime < time[newx][newy]) {
                        time[newx][newy] = needtime;
                        pq.push({needtime, {newx, newy}});
                    }
                }
            }
        }

        return -1;        
    }
};