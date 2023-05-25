class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
       if(k==0 || n>=k-1+maxPts){return 1.00;}
        int mx=k-1+maxPts;
        //dp[i] is the probablity of getting point i
        vector<double> dp(n+1,0.0);
        dp[0]=1.0;
        double probablity=0.0,windowsum=1.0;
        for(int i=1;i<=n;i++){
            dp[i]=windowsum/maxPts;
            if(i<k){windowsum+=dp[i];}
            else{probablity+=dp[i];}
            if(i>=maxPts){windowsum-=dp[i-maxPts];}
        }
        return probablity;
    }
};