class Solution {
public:
   int solve(string &s,int index,int power,long long score,int& k,vector<int>& dp){
        if(index<0)return 0;
        if(dp[index]!=-1)return dp[index];
        
        int include=0;
        if(s[index]=='1'){
            if(score+pow(2,power)<=k){
                include=1+solve(s,index-1,power+1,score+ pow(2,power),k,dp);
            }
        }else{
            include=1+solve(s,index-1,power+1,score,k,dp);
        }
        int notinclude=solve(s,index-1,power,score,k,dp);
        return dp[index]=max(include,notinclude);
    }
    int longestSubsequence(string s, int k) {
        int n=s.length();
        vector<int> dp(n+1,-1);
        int power=0;
        long long score=0;
        return solve(s,n-1,power,score,k,dp);
    }
};