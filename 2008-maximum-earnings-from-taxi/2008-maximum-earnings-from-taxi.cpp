class Solution {
public:
    int m,l;
    long long f(int i,vector<vector<int>>& rides,vector<long long> &dp,vector<int> &st){
        if(i>=m){return 0;}
        if(dp[i]!=-1){return dp[i];}
        int s=rides[i][0];
        int e=rides[i][1];
        int tip=rides[i][2];
        int ind= lower_bound(st.begin(),st.end(),e)- st.begin();
        long long a=e-s+tip+f(ind,rides,dp,st);
        long long b=f(i+1,rides,dp,st);
        return dp[i]=max(a,b);
    }
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        m=rides.size();l=n;
        sort(rides.begin(),rides.end());
        vector<int> st(m);
        for(int i=0;i<m;i++){st[i]=rides[i][0];}
        vector<long long> dp(m,-1);
        return f(0,rides,dp,st);
    }
};