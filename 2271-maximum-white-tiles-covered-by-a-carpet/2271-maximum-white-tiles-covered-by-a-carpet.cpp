class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& t, int len) {
    int res = 0, j = 0, cover = 0;
    sort(begin(t), end(t));
    for (int i = 0; res < len && i < t.size(); )
        if (t[j][0] + len > t[i][1]) {
            cover += t[i][1] - t[i][0] + 1;
            res = max(res, cover);
            ++i;
        }
        else {
            int partial = max(0, t[j][0] + len - t[i][0]);
            res = max(res, cover + partial);
            cover -= (t[j][1] - t[j][0] + 1);
            ++j;
        }
    return res;
    }
};