class Solution {
public:
    string stoneGameIII(vector<int>& a) {
        int n=a.size();
        int dp[3];
        memset(dp,0,sizeof(dp));
        for(int i=n-1;i>=0;i--){
            int one=a[i]-dp[(i+1)%3];
            int two=-1e9;
            if(i+1<n){two=a[i]+a[i+1]-dp[(i+2)%3];}
            int three=-1e9;
            if(i+2<n){three=a[i]+a[i+1]+a[i+2]-dp[(i+3)%3];}
            dp[i%3]=max({one,two,three});
        }
        if(dp[0]>0){return "Alice";}
        else if(dp[0]<0){return "Bob";}
        return "Tie";
    }
};