class Solution {
public:
    int l;
    int mxz,mxo;
    int dp[601][101][101];
    int f(int i,vector<string>& strs,map<string,pair<int,int>> &freq,int curz,int curo){
        if(i==l){return 0;}
        if(dp[i][curz][curo]!=-1){return dp[i][curz][curo];}
        int ans=f(i+1,strs,freq,curz,curo);
        int zer=freq[strs[i]].first,one=freq[strs[i]].second;
        if(curz+zer<=mxz && curo+one<=mxo){
            ans=max(ans,1+f(i+1,strs,freq,curz+zer,curo+one));
        }
        return dp[i][curz][curo]=ans;
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
        memset(dp,-1,sizeof(dp));
        return f(0,strs,freq,0,0);
    }
};