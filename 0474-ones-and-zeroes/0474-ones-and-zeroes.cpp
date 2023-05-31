class Solution {
public:
    int l;
    int mxz,mxo;
    int f(int i,vector<string>& strs,map<string,pair<int,int>> &freq,pair<int,int> cur,vector<map<pair<int,int>,int>>&dp){
        if(i==l){return 0;}
        if(dp[i].find(cur)!=dp[i].end()){return dp[i][cur];}
        int ans=f(i+1,strs,freq,cur,dp);
        int zer=freq[strs[i]].first,one=freq[strs[i]].second;
        int curz=cur.first,curo=cur.second;
        if(curz+zer<=mxz && curo+one<=mxo){
            ans=max(ans,1+f(i+1,strs,freq,{curz+zer,curo+one},dp));
        }
        return dp[i][cur]=ans;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        mxz=m;mxo=n;
        l=strs.size();
        map<string,pair<int,int>> freq;
        for(auto i:strs){
            int z=0,o=0;
            for(auto j:i){
                if(j=='0'){z++;}
                else{o++;}
            }
            freq[i]={z,o};
        }
        vector<map<pair<int,int>,int>> dp(l+1);
        return f(0,strs,freq,{0,0},dp);
    }
};