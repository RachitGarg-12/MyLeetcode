//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> pre(wordList.begin(),wordList.end());
        int n=beginWord.size();
        queue<vector<string>> q;
        q.push({beginWord});
        vector<vector<string>> ans;
        while(!q.empty()){
            int sz=q.size();
            vector<string> mark;
            bool b=false;
            while(sz--){
               vector<string> seq=q.front();q.pop();
               string cur=seq.back();
               string t;
               for(int i=0;i<n;i++){
                   t=cur;
                  for(char c='a';c<='z';c++){
                      t[i]=c;
                      if(pre.count(t)>0){
                          seq.push_back(t);
                          q.push(seq);
                          if(t==endWord){b=true;ans.push_back(seq);}
                          mark.push_back(t);
                          seq.pop_back();
                      }
                  }
               }
            }
            if(b){break;}
            for(auto i:mark){pre.erase(i);}
        }
        return ans;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends