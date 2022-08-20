class Solution {
public:
    int jump(vector<int>& a) {
        int n=a.size();vector<int> dp(n,0);
        // dp[i] min number of steps u need to reach from i to n-1
        dp[n-1]=0;
        for(int i=n-2;i>=0;i--){
            int ans=1e6;
          for(int j=1;j<=a[i];j++){
            if(i+j>=n) break;
            int temp= 1+ dp[i+j];
            ans=min(ans,temp);
           }  
         dp[i]=ans;
        }
        for(auto i:dp) cout<<i<<" ";
       return dp[0]; // we return dp[0] as we want to reach from 0 to n-1 
    }
};