class Solution {
public:
    bool func(string &s1, string &s2, string &s3, int i1, int i3, vector<vector<int>>&dp){
        if(i3 >= s3.length()){
            return true;
        }
        
        if(dp[i3][i1] != -1) return (bool)dp[i3][i1];
        
        int i2 = i3 - i1;
        bool p1 = false, p2 = false;
        
        if(i1 < s1.length() && s1[i1] == s3[i3]){
            p1 = func(s1, s2, s3, i1 + 1, i3 + 1, dp);
        }
        
        if(i2 < s2.length() && s2[i2] == s3[i3]){
            p2 = func(s1, s2, s3, i1, i3 + 1, dp);
        }
        
        dp[i3][i1] = (int)(p1 || p2);
        
        return p1 || p2;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length() + s2.length() != s3.length()) return false;
        vector<vector<int>>dp(s3.length() + 1, vector<int>(s1.length() + 1, -1));
        return func(s1, s2, s3, 0, 0, dp);
    }
};