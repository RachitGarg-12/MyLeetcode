//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    vector<int> topoSort(int V, vector<int> adj[]) {   
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
	    return ans;
	}
    string findOrder(string dict[], int n, int k) {
        vector<int> adj[k];
        for(int i=0;i<n-1;i++){
            int j=i+1;
            int a=0,b=0;int l=min(dict[i].size(),dict[j].size());
            while(a<l && b<l && dict[i][a]==dict[j][b]){
                a++;b++;
            }
            if(a==l || b==l){continue;}
            adj[dict[i][a]-'a'].push_back(dict[j][b]-'a');
        }
        vector<int> v=topoSort(k,adj);
        string ans="";
        for(auto i:v){ans+=char('a'+i);}
        return ans;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends