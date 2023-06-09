//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	set<string> ans;
	int n;
	void f(vector<int>vis,string cur,string&S){
	    if(cur.size()==n){ans.insert(cur);return;}
	    for(int i=0;i<n;i++){
	        if(!vis[i]){
	            cur+=S[i];vis[i]=1;
	            f(vis,cur,S);
	            cur.pop_back();vis[i]=0;
	        }
	    }
	}
	vector<string>find_permutation(string S){
		   n=S.size();
		   vector<int> vis(n,0);
		   f(vis,"",S);
		   vector<string> res;
		   for(auto i:ans){res.push_back(i);}
		   return res;
	}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends