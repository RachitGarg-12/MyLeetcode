class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string,char> m;
        unordered_map<char,string> n;
        string cur="";
        int j=0;
        for(auto i:s){
            if(i==' '){
                if(m.find(cur)!=m.end()){
                    if(m[cur]!=pattern[j]){return false;}
                }
                else if(n.find(pattern[j])!=n.end()){
                     if(n[pattern[j]]!=cur){return false;}
                }
                m[cur]=pattern[j];n[pattern[j]]=cur;j++;cur="";
            }
            else{cur+=i;}
        }
        if(m.find(cur)!=m.end()){
            if(m[cur]!=pattern[j]){return false;}
        }
        else if(n.find(pattern[j])!=n.end()){
            if(n[pattern[j]]!=cur){return false;}
        }
        if(j<pattern.size()-1)return false;
        return true;
    }
};