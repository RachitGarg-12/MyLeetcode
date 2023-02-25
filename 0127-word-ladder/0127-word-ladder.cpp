class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n=beginWord.size(),l=wordList.size();
        bool b=false;
        unordered_map<string,vector<string>> m;
        for(int j=0;j<l;j++){
            string cur=wordList[j];
            if(cur==endWord){b=true;}
            int req=0;
            for(int i=0;i<n;i++){
                if(beginWord[i]!=wordList[j][i]){req++;}
            }
            if(req==1){
                m[beginWord].push_back(wordList[j]);
                m[wordList[j]].push_back(beginWord);
            }
        }
        if(b==false){return 0;}
        for(int i=0;i<l-1;i++){
            string cur=wordList[i];
            if(cur==beginWord){continue;}
            for(int j=i+1;j<l;j++){
                string sec=wordList[j];
                if(sec==beginWord){continue;}
                int req=0;
                for(int k=0;k<n;k++){
                    if(cur[k]!=sec[k]){req++;}
                }
                if(req==1){
                    m[cur].push_back(sec);
                    m[sec].push_back(cur);
                }
            }
        }
        queue<string> q;
        unordered_map<string,int> vis;
        q.push(beginWord);
        vis[beginWord]=1;
        int level=2;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                string node=q.front();q.pop();
                for(auto i:m[node]){
                    if(!vis[i]){
                        if(i==endWord){return level;}
                        if(!vis[i]){vis[i]=1;q.push(i);}
                    }
                }
            }
            level++;
        }
      return 0;
    }
};