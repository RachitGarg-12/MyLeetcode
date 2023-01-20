class Solution {
public:
    int n,m;
    vector<vector<vector<int>>> dp;
    int f(int i,int j1,int j2,vector<vector<int>>& a,vector<vector<vector<int>>> &dp){
        if(j1<0 || j1>=m || j2<0 || j2>=m){return -1e8;}
        if(i==n-1){
            if(j1==j2){return a[i][j1];}
            else{return a[i][j1]+a[i][j2];}
        }
        if(dp[i][j1][j2]!=-1){return dp[i][j1][j2];}
        int maxi=0;
        for(int k=-1;k<2;k++){
            for(int j=-1;j<2;j++){
               if(j1==j2){
                   maxi=max(maxi,a[i][j1]+f(i+1,j1+k,j2+j,a,dp));
               } 
                else{
                   maxi=max(maxi,a[i][j1]+a[i][j2]+f(i+1,j1+k,j2+j,a,dp)); 
                }
            }
        }
        return dp[i][j1][j2]=maxi;
    }
    int cherryPickup(vector<vector<int>>& a) {
        n=a.size();m=a[0].size();
        dp.resize(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return f(0,0,m-1,a,dp);
    }
};