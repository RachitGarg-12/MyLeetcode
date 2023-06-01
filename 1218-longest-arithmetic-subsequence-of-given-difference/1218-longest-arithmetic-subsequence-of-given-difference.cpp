class Solution {
public:
    int longestSubsequence(vector<int>& a, int dif) {
        int n=a.size();
        unordered_map<int,int> dp;
        //dp[x] is the max len of a subsequence of the given diff whose last element is x
        int ans=1;
        for(int i=0;i<n;i++){
            if(dp.find(a[i]-dif)==dp.end()){dp[a[i]]=1;continue;}
            dp[a[i]]=1+dp[a[i]-dif];
            ans=max(ans,dp[a[i]]);
        }
        return ans;
    }
};