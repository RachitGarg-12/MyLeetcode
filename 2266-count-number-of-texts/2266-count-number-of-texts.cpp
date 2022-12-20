class Solution {
public:
    int dp[100005];
    int mod = 1e9+7;
    int solve(string &str, int idx) {
        if(idx == str.length()) return 1;
        if(dp[idx] != -1) return dp[idx];
        int maxKeyPress = (str[idx] == '7' || str[idx] == '9') ? 4 : 3;
        long long currIndex = idx, pressFrequency = 1, ans = 0;
        while(pressFrequency <= maxKeyPress && str[currIndex] == str[idx]) {
            ++currIndex;
            ++pressFrequency;
            ans += solve(str, currIndex) % mod;
        }
        return dp[idx] = ans%mod;
    }
    int countTexts(string pressedKeys) {
        memset(dp, -1, sizeof(dp));
        return solve(pressedKeys, 0) % mod;
    }
};