class Solution {
public:
    vector<int> dp;
int rec(int x){
    //basecase
    if(x==0)return 1;
    if(dp[x]!=-1)return dp[x];
    int ans=0;
    for(int i=1;i*i<=x;i++){
        if(x%i==0){
        return dp[i]=!rec(x-i);}
    }
    return dp[x]=false;
}
    bool divisorGame(int n) {
        dp.resize(n+1,-1);
        return rec(n);
    }
};