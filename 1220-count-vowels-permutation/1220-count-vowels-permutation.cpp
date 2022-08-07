class Solution {
public:
    const int mod=1e9+7;
    int countVowelPermutation(int n) {
        long long dp[5][n+1];// dp[i][j] is the number possible string of length i that end at vowel k
        dp[0][1]=dp[1][1]=dp[2][1]=dp[3][1]=dp[4][1]=1;
        for(int i=2;i<=n;i++){
            dp[0][i]=dp[1][i-1];//a can only be followed by e
            dp[1][i]=(dp[0][i-1]+dp[2][i-1])%mod;
            dp[2][i]=(dp[0][i-1]+dp[1][i-1]+dp[3][i-1]+dp[4][i-1])%mod;
            dp[3][i]=(dp[2][i-1]+dp[4][i-1])%mod;
            dp[4][i]=dp[0][i-1];
        }
       return (dp[0][n]+dp[1][n]+dp[2][n]+dp[3][n]+dp[4][n])%mod;
    }
};