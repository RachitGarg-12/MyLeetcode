class Solution {
public:
    vector<int> dp;
    int rec(int i,int last,bool bech,vector<int>& a){
        if(i==a.size()){return 0;}
        if(dp[i]!=-1){return dp[i];}
        if(a[i]<last || bech==false){rec(i+1,a[i],true,a);}
        int ans = max(rec(i+1,a[i],false,a)+a[i]-last,rec(i+1,last,true,a));
        return dp[i]=ans;
    }
    int maxProfit(vector<int>& a) {
        int n=a.size();
        dp.resize(n,-1);dp[0]=0;
        int ans=rec(1,a[0],true,a);
        for(auto i:dp){ans=max(ans,i);}
        return ans;
    }
};