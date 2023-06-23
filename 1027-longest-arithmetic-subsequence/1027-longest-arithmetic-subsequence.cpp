class Solution {
public:
    int longestArithSeqLength(vector<int>& a) {
         int n=a.size();
         vector<vector<int>> dp(n+1,vector<int>(1002,0));
        int ans=0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                int dif=500+a[i]-a[j];
                dp[i][dif]=1+dp[j][dif];
                ans=max(ans,dp[i][dif]);
            }
        }
        return ans+1;
    }
};