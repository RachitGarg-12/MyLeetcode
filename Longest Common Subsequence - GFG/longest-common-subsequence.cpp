//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int f(int i,int j,string &s1,string &s2,vector<vector<int>> &dp){
        if(i<0 || j<0){return 0;}
        if(dp[i][j]!=-1){return dp[i][j];}
        //if present equal
        if(s1[i]==s2[j]){return 1+f(i-1,j-1,s1,s2,dp);}
        //not equal
        return dp[i][j]=max(f(i-1,j,s1,s2,dp),f(i,j-1,s1,s2,dp));
    }
    int lcs(int x, int y, string s1, string s2){
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


//{ Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends