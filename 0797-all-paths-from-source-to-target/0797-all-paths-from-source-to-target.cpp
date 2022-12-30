class Solution {
public:
    int n;
    vector<vector<int>> res;
    void  f(vector<vector<int>>& graph,int cur,vector<int> ans,vector<int> vis){
        vis[cur]=true;
        if(cur==n-1){res.push_back(ans);}
        for(auto i:graph[cur]){
            if(!vis[i]){
                ans.push_back(i);
                f(graph,i,ans,vis);
                ans.pop_back();
            }
        } 
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n=graph.size();
        vector<int> vis(n,false);
        f(graph,0,{0},vis);
        return res;
    }
};