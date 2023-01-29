class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int x=s1.size(),y=s2.size();
        vector<vector<int>> dp(x+1,vector<int>(y+1,0));
        bool b=false;
        // dp[i][j]represents lcs in s1(0..i) && s2(0..j) so if a particular (0,i) || (i,0) is equal then all i after that will have ans 1 and can only have one as we have 1 element
        for(int i=0;i<y;i++){
            if(s1[0]==s2[i]){b=true;}
            if(b==true){dp[0][i]=1;}
        }
        b=false;
        for(int i=0;i<x;i++){
            if(s2[0]==s1[i]){b=true;}
            if(b){dp[i][0]=1;}
        }
        for(int i=1;i<x;i++){
            for(int j=1;j<y;j++){
               if(s1[i]==s2[j]){dp[i][j]=1+dp[i-1][j-1];}
               else{dp[i][j]=max(dp[i-1][j],dp[i][j-1]);}                
            }
        }
        return dp[x-1][y-1];
    }
};