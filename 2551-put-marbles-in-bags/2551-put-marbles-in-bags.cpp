class Solution {
public:
    int n,k;
    long long dp[100005][105];
    long long solve(int i,int j,vector<int>& weights){
        if(i==j)
            return weights[i];
        if(dp[i][j]!=-1)
            return dp[i][j];
        long long ans=INT_MIN;
        for(int k=i;k<j;k++)
        {
            ans=max(ans,solve(i,k,weights)+solve(k+1,j,weights)+weights[i]+weights[j]);
        }
        return dp[i][j]=ans;
    }
    long long putMarbles(vector<int>& weights, int k) {
        int n=weights.size();
        if(k==n){return 0;}
        long long a=0,b=0;k--;
        vector<long long> a1(n-1);
        for(int i=0;i<n-1;i++){a1[i]=weights[i]+weights[i+1];}
        sort(a1.begin(),a1.end());
        vector<long long> a2=a1;
        reverse(a2.begin(),a2.end());
        for(int i=0;i<k;i++){a+=a1[i];b+=a2[i];}
        long long ans=a-b;
        return abs(ans);
    }
};