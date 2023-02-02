class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int n=words.size();
        unordered_map<char,int> m;
        for(int i=0;i<26;i++){m[order[i]]=i;}
        for(int i=0;i<n-1;i++){
            int s=min(words[i].size(),words[i+1].size());
            int j=0;
            while(j<s && words[i][j]==words[i+1][j]){j++;}
            if(j==s){
                if(words[i].size()>words[i+1].size()){return false;}
            }
            else if(m[words[i][j]]>m[words[i+1][j]]){return false;}
        }
        return true;
    }
};