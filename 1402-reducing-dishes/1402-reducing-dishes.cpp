class Solution {
public:
    int n;
    int f(int i,int ele,vector<int>& satisfaction, vector<vector<int>> &dp){
        if(i>=n){return 0;}
        if(dp[i][ele]!=-1){return dp[i][ele];}
        int ans=0;
        if(satisfaction[i]<=0){
            ans=f(i+1,ele,satisfaction,dp);
        }
        ans=max(ans,satisfaction[i]*(ele+1)+f(i+1,ele+1,satisfaction,dp));
        return dp[i][ele]=ans;
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        n=satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return f(0,0,satisfaction,dp);
    }
};