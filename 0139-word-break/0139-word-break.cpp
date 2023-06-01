class Solution {
public:
    int n;
    bool f(int i,string &s,unordered_map<string,bool> &dict,vector<int> &dp){
        if(i==n){return false;}
        if(dp[i]!=-1){return dp[i];}
        string pre="";
        bool ans=false;
        for(int it=i;it<n;it++){
           pre+=s[it];
           if(dict.find(pre)!=dict.end()){
               if(it==n-1){return dp[i]=true;}
               ans|=f(it+1,s,dict,dp);
           }            
        }
        return dp[i]=ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        n=s.size();
        unordered_map<string,bool> dict;
        for(auto i:wordDict){
            dict[i]=true;
        }
        vector<int> dp(n+1,-1);
        return f(0,s,dict,dp);
    }
};