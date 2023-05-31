class Solution {
public:
    int l;
    int mxz,mxo;
    // int dp[601][101][101];
    // int f(int i,vector<string>& strs,map<string,pair<int,int>> &freq,int curz,int curo){
    //     if(i==l){return 0;}
    //     if(dp[i][curz][curo]!=-1){return dp[i][curz][curo];}
    //     int ans=f(i+1,strs,freq,curz,curo);
    //     int zer=freq[strs[i]].first,one=freq[strs[i]].second;
    //     if(curz+zer<=mxz && curo+one<=mxo){
    //         ans=max(ans,1+f(i+1,strs,freq,curz+zer,curo+one));
    //     }
    //     return dp[i][curz][curo]=ans;
    // }
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
        int dp[l+1][m+1][n+1];
        for(int i=l;i>=0;i--){
            for(int curz=m;curz>=0;curz--){
                for(int curo=n;curo>=0;curo--){
                    if(i==l){dp[i][curz][curo]=0;continue;}
                    int ans=dp[i+1][curz][curo];
                    int zer=freq[strs[i]].first,one=freq[strs[i]].second;
                    if(curz+zer<=mxz && curo+one<=mxo){
                        ans=max(ans,1+dp[i+1][curz+zer][curo+one]);
                    }
                    dp[i][curz][curo]=ans;                    
                }
            }
        }
        return dp[0][0][0];
    }
};