class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(V);
        for(auto i:prerequisites){
            adj[i[0]].push_back(i[1]);
        }
        vector<int> indeg(V,0);
	    queue<int> q;
	    for(int i=0;i<V;i++){
	        for(auto j:adj[i]){
	            indeg[j]++;
	        }
	    }
	    for(int i=0;i<V;i++){
	        if(indeg[i]==0){q.push(i);}
	    }
	    vector<int> ans;
	    while(!q.empty()){
	        int node=q.front();
	        ans.push_back(node);
	        q.pop();
	        for(auto i:adj[node]){
	            if(indeg[i]>0){
	                indeg[i]--;
	                if(indeg[i]==0){q.push(i);}
	            }
	        }
	    }
        if(ans.size()!=V){return {};}
        reverse(ans.begin(),ans.end());
        return ans;
    }
};