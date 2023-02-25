class Solution {
public:
//     int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
//         queue<string> q;
//         set<string> st,words;
//         for(string s:wordList)
//             words.insert(s);
//         st.insert(beginWord);
//         q.push(beginWord);
//         int res=0;
//         while(q.size()){
//             int n = q.size();
//             res++;
//             for(int i=0;i<n;i++){
//                 string s = q.front();
//                 if(s==endWord)
//                     return res;
//                 q.pop();
//                 string t;
//                 for(int i=0;i<s.size();i++){
//                     t=s;
//                     for(int j='a';j<='z';j++){
//                         t[i]=j;
//                         if(words.count(t) and !st.count(t)){
//                             q.push(t);
//                             st.insert(t);
//                         }
//                     }
//                 }
//             }
//         }
//         return 0;
//     }
// };
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
       set<string> pre,vis;
        for(auto i:wordList){
            pre.insert(i);
        }
        int n=beginWord.size();
        queue<string> q;
        q.push(beginWord);
        vis.insert(beginWord);
        int level=2;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
            string cur=q.front();q.pop();
            string t;
            for(int i=0;i<n;i++){
                t=cur;
               for(char c='a';c<='z';c++){
                   t[i]=c;
                   if(pre.count(t)==1 && !vis.count(t)){
                       if(t==endWord){return level;}
                       q.push(t);vis.insert(t);
                   }
               }
            }
            }
            level++;
        }
      return 0;
    }
};