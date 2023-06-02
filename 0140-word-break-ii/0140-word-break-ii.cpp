class Solution {
public:
    int n;
    vector<string> ans;
    void f(int i,string &s,unordered_map<string,bool> &dict,string cur){
        if(i==n){
            cur.pop_back();
            ans.push_back(cur);
        }
        string pre="";
        for(int it=i;it<n;it++){
           pre+=s[it];
           if(dict.find(pre)!=dict.end()){
               f(it+1,s,dict,cur+pre+" ");
           }            
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        n=s.size();
        unordered_map<string,bool> dict;
        for(auto i:wordDict){
            dict[i]=true;
        }
        f(0,s,dict,"");
        return ans;
    }
};