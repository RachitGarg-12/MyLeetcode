class Solution {
public:
    int n;
    vector<string> ans;
    void f(int i,string &s,unordered_map<string,bool> &dict,string cur){
        string pre="";
        for(int it=i;it<n;it++){
           pre+=s[it];
           if(dict.find(pre)!=dict.end()){
               if(it==n-1){
                   if(cur.size()==0){ans.push_back(pre);}
                   else{ans.push_back(cur+' '+pre);}
                   return;
               }
               if(cur.size()==0){f(it+1,s,dict,pre);}
               else{f(it+1,s,dict,cur+' '+pre);}
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