class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int> pre;
        for(auto i:wordList){
            pre[i]=1;
        }
        int n=beginWord.size();
        queue<string> q;
        unordered_map<string,int> vis;
        q.push(beginWord);
        vis[beginWord]=1;
        int level=2;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
            string cur=q.front();q.pop();
            for(int i=0;i<n;i++){
               for(char c='a';c<='z';c++){
                   string t=cur;
                   t[i]=c;
                   if(!vis[t] && pre[t]){
                       if(t==endWord){return level;}
                       q.push(t);vis[t]=1;
                   }
               }
            }
            }
            level++;
        }
      return 0;
    }
};