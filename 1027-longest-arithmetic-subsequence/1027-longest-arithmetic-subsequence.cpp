class Solution {
public:
    int longestArithSeqLength(vector<int>& a) {
        int n=a.size();
        if(n<=2){return n;}
        int ans=1;
        vector<vector<int>> dp(n+1,vector<int>(1001,1));
        // dp[i][diff] equals to the length of arithmetic sequence at i with difference diff
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                int dif=a[i]-a[j]+500;
                dp[i][dif]=max(2,dp[j][dif]+1);
                ans=max(ans,dp[i][dif]);
            }
        }
        return ans;
    }
};