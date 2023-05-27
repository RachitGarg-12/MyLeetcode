class Solution {
public:
    string stoneGameIII(vector<int>& a) {
        int n=a.size();
        vector<int> dp(n+1,-1e9);
        dp[n]=0;
        for(int i=n-1;i>=0;i--){
            int one=a[i]-dp[i+1];
            int two=-1e9;
            if(i+2<=n){two=a[i]+a[i+1]-dp[i+2];}
            int three=-1e9;
            if(i+3<=n){three=a[i]+a[i+1]+a[i+2]-dp[i+3];}
            dp[i]=max({one,two,three});
        }
        if(dp[0]>0){return "Alice";}
        else if(dp[0]<0){return "Bob";}
        return "Tie";
    }
};