class Solution {
public:
    int n;
    int minimumTotal(vector<vector<int>>& triangle) {
        n=triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        dp[0][0]=triangle[0][0];
        for(int i=1;i<n;i++){dp[i][0]=triangle[i][0]+dp[i-1][0];}
        int ans=dp[n-1][0];
        for(int i=1;i<n;i++){
            for(int j=1;j<=i;j++){
                int left=dp[i-1][j-1];
                int up=1e9;
                if(j!=i){up=dp[i-1][j];}
                dp[i][j]=triangle[i][j]+min(left,up);
                if(i==n-1){ans=min(ans,dp[i][j]);}
            }
        }
        
        return ans;
    }
};