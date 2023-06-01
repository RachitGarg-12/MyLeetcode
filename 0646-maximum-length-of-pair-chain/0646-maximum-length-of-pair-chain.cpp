class Solution {
public:
    int findLongestChain(vector<vector<int>>& a) {
        int n=a.size();
        sort(a.begin(),a.end());
        vector<int> dp(n,1);
        int maxi=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(a[i][0]>a[j][1] && dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                }
            }
            maxi=max(maxi,dp[i]);
        }
      return maxi;  
    }
};