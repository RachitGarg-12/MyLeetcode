class Solution {
public:
    unordered_map<string,int> m;
    int n;
    vector<vector<string>> ans;
    string b;
    void dfs(string word,vector<string> &seq){
        if(word==b){
            reverse(seq.begin(),seq.end());
            ans.push_back(seq);
            reverse(seq.begin(),seq.end());
            return;
        }
        int steps=m[word];
        for(int i=0;i<n;i++){
            char original=word[i];
            for(char c='a';c<='z';c++){
                word[i]=c;
                if(m.find(word)!=m.end() && m[word]==steps-1){
                    seq.push_back(word);
                    dfs(word,seq);
                    seq.pop_back();
                }
                word[i]=original;
            }
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        b=beginWord;
        unordered_set<string> pre(wordList.begin(),wordList.end());
        n=beginWord.size();
        queue<string> q;
        q.push(beginWord);
        pre.erase(beginWord);
        m[beginWord]=1;
        while(!q.empty()){
            string cur=q.front();q.pop();
            int lev=m[cur];
            if(cur==endWord){break;}
            for(int i=0;i<n;i++){
                char original=cur[i];
                for(char c='a';c<='z';c++){
                    cur[i]=c;
                    if(pre.count(cur)){
                        q.push(cur);
                        pre.erase(cur);
                        m[cur]=lev+1;
                    }
                }
                cur[i]=original;
            }
        }
        if(m.find(endWord)!=m.end()){
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord,seq);
        }
        
        return ans;
    }
};