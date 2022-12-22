class Solution {
public:
    vector<map<int, pair<int, int>>> graph;

    int dfs(int i, int j){
        if(j!=-1 && graph[j][i].first != -1)
            return graph[j][i].first;

        int sum = 0, count = 0;
        for(auto p : graph[i]){
            if(p.first != j){
                sum += dfs(p.first, i);
                int x = graph[i][p.first].second + 1;

                sum += x;
                count += x;
            }
        }

        if(j != -1){
            graph[j][i].first = sum;
            graph[j][i].second = count;
        }
        return sum;
    }
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> ans(n);
        graph = vector<map<int, pair<int, int>>>(n);

        for(auto ed : edges){
            graph[ed[0]][ed[1]] = {-1,0};
            graph[ed[1]][ed[0]] = {-1,0};
        }

        for(int i = 0; i<n; i++)
            ans[i] = dfs(i, -1);

        return ans;
    }
};