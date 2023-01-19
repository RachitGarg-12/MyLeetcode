class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();int m=matrix[0].size();int ans=INT_MAX;
        vector<vector<int>> dp(n,vector<int> (m,INT_MAX));
        for(int i=0;i<m;i++){
          dp[0][i]=matrix[0][i];
          if(n==1){ans=min(ans,dp[0][i]);}
        }
        //dp[i][j] is the min sum reach (i,j) from any cell in the first row
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                int left=j>0?dp[i-1][j-1]:INT_MAX;
                int right=j<m-1?dp[i-1][j+1]:INT_MAX;
                dp[i][j]=matrix[i][j]+min(dp[i-1][j],min(left,right));
                if(i==n-1){ans=min(ans,dp[i][j]);}
            }
        }
        
        return ans;     
    }
};