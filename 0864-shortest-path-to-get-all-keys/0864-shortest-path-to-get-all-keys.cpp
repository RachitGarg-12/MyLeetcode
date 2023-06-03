class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int sr, sc, key_count = 0, n = grid.size(), m = grid[0].length();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char ch = grid[i][j];
                if (ch == '@') sr = i, sc = j;
                if (ch >= 'a' && ch <= 'z') key_count = ((1 << (ch - 'a')) | key_count);
            }
        }

        int key = 0, ans = -1;
        queue<pair<pair<int, int>, pair<int, int>>> q;
        q.push({{sr, sc}, {0, 0}});
        int vis[n + 1][m + 1][key_count + 1];
        memset(vis, 0, sizeof(vis));
        vis[sr][sc][key] = 1;
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int row = it.first.first, col = it.first.second, koi = it.second.first, steps = it.second.second;
            if (koi == key_count) {
                return steps;
            }
            vector<int> dr = { -1, 0, 1, 0}, dc = {0, 1, 0, -1};
            for (int i = 0; i < 4; i++) {
                int nrow = row + dr[i], ncol = col + dc[i];
                if (nrow < 0 || nrow >= n || ncol < 0 || ncol >= m || grid[nrow][ncol] == '#') continue;
                char ch = grid[nrow][ncol];
                if (ch >= 'A' && ch <= 'F') {
                    if ((koi >> (ch - 'A')) & 1) { // set
                        if (!vis[nrow][ncol][koi]) {
                            q.push({{nrow, ncol}, {koi, steps + 1}});
                            vis[nrow][ncol][koi] = 1;
                        }
                    }
                }
                else if (ch >= 'a' && ch <= 'f') {
                    int res = (1 << (ch - 'a')) | koi;
                    //cout<<res<<endl;
                    if (!vis[nrow][ncol][res]) {
                        q.push({{nrow, ncol}, {res, steps + 1}});
                        vis[nrow][ncol][res] = 1;
                    }
                }
                else {
                    if (!vis[nrow][ncol][koi]) {
                        q.push({{nrow, ncol}, {koi, steps + 1}});
                        vis[nrow][ncol][koi] = 1;
                    }
                }
            }
        }
        return ans;
    }
};