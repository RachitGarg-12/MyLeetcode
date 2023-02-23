class Solution {
public:
    //detect cycle in a directed graph
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        for(auto i:prerequisites){
            adj[i[0]].push_back(i[1]);
        }
        vector<int> indeg(n,0);
	    queue<int> q;
	    for(int i=0;i<n;i++){
	        for(auto j:adj[i]){
	            indeg[j]++;
	        }
	    }
	    for(int i=0;i<n;i++){
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
	    if(ans.size()==n){return true;}
	    return false;
    }
};