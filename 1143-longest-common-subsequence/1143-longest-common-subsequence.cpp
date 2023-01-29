class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int x=s1.size(),y=s2.size();
        vector<vector<int>> dp(x+1,vector<int>(y+1,0));
        //shigting one index to right as our base case is for -1 index
        // so here ind i represents i-1 of string, as i<0 || j<0 was 0 ,so
        for(int i=0;i<y;i++){
            dp[0][i]=0;
        }
        for(int i=0;i<x;i++){
            dp[i][0]=0;
        }
        
        for(int i=1;i<=x;i++){
            for(int j=1;j<=y;j++){
               if(s1[i-1]==s2[j-1]){dp[i][j]=1+dp[i-1][j-1];}
               else{dp[i][j]=max(dp[i-1][j],dp[i][j-1]);}                
            }
        }
        return dp[x][y];
    }
};