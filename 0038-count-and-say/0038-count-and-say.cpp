class Solution {
public:
  
    string countAndSay(int n) {
        if(n==1)return "1";
        string ans="1";
        for(int i=2;i<=n;i++){
            vector<pair<char,int>> m;char cur=ans[0];int f=1;
            for(int i=1;i<ans.size();i++){
                if(ans[i]==cur){f++;}
                else{
                    m.push_back({cur,f});cur=ans[i];f=1;
                }
            }
            m.push_back({cur,f});
            string ne="";
            for(auto i:m){ne+=to_string(i.second);ne+=i.first;}
            ans=ne;
        }
        return ans;
    }
};