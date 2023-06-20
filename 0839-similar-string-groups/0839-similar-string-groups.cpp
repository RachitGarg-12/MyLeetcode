class Solution {
public:
    bool similar(string&a,string&b){
        int dif=0,l=a.size();
        for(int i=0;i<l;i++){
            if(a[i]!=b[i]){dif++;}
        }
        return dif==0 || dif==2;
    }
    void dfs(int i,vector<int>&vis,vector<vector<int>>&graph){
        vis[i]=1;
        for(auto it:graph[i]){
            if(!vis[it]){
                dfs(it,vis,graph);
            }
        }
    }
    int numSimilarGroups(vector<string>& strs) {
        int n=strs.size();
        vector<vector<int>> graph(n);
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(similar(strs[i],strs[j])){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        vector<int> vis(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans++;dfs(i,vis,graph);
            }
        }
        return ans;
    }
};