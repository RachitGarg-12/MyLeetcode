class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1);
        
        for(int i=0;i<n;i++){
         if(graph[i].size()>0 && color[i]==-1){
         stack<int> q;
          q.push(i);color[i]=0;
        while(!q.empty()){
            int k=q.top();
            q.pop();
            int cn=(color[k]==0)?1:0;
            for(auto j:graph[k]){
                if(color[j]==-1){
                    color[j]=cn;
                    q.push(j);
                }
                else{
                    if(color[j]!=cn)return false;
                }
            }
        }
         }
        }
        return true;
    }
    
};