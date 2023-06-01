class Solution {
public:
    int longestSubsequence(vector<int>& a, int dif) {
        int n=a.size();
        map<int,int> dp;
        //dp[x] is the max len of a subsequence of the given diff whose last element is x
        int ans=0;
        for(int i=0;i<n;i++){
            dp[a[i]]=1+dp[a[i]-dif];
            ans=max(ans,dp[a[i]]);
        }
        return ans;
    }
};