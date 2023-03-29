class Solution {
public:
    int n;
    int f(int i,vector<int>& days, vector<int>& costs,vector<int> &dp){
        if(i>=n){return 0;}
        if(dp[i]!=-1){return dp[i];}
        int ans=costs[0]+f(i+1,days,costs,dp);
        int cur=days[i];
        int t=i;
        while(t<n && days[t]-cur<=6){t++;}
        ans=min(ans,costs[1]+f(t,days,costs,dp));
        int t2=i;
        while(t2<n && days[t2]-cur<=29){t2++;}
        ans=min(ans,costs[2]+f(t2,days,costs,dp));
        return dp[i]=ans;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        n=days.size();
        vector<int> dp(n,-1);
        return f(0,days,costs,dp);
    }
};