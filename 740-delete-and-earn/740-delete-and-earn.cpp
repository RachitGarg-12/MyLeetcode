class Solution {
public:
    int deleteAndEarn(vector<int>& a) {
        vector<int> dp(10001,0);
        vector<int> ar(10001,0);int ans=0;
        for(int i:a) ar[i]+=i;   //we set all element prersent by their value in arr
        dp[0]=0;dp[1]=ar[1];
        for(int i=2;i<10001;i++){
            dp[i]=max(dp[i-2]+ar[i],dp[i-1]);
        }
        return dp[10000];
    }
};