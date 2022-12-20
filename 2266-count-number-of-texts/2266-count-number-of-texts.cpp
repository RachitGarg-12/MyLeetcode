class Solution {
public:
    int mod=1e9+7;
    int dp[100005];
    int rec(string &s,int ind){
        if(ind==s.length())return 1;
        if(dp[ind]!=-1)return dp[ind];
        int len=(s[ind]=='7' || s[ind]=='9')?4:3;
        long long ans=0,press=1,curind=ind;
        while(press<=len && s[curind]==s[ind]){
            ++curind;
            ++press;
            ans+= rec(s,curind)%mod;
        }
        return dp[ind]=ans%mod;
    }
    int countTexts(string s) {
      memset(dp, -1, sizeof(dp));
        return rec(s,0)%mod;
    }
};