//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	    int lcs(string s1, string s2) {
        int x=s1.size(),y=s2.size();
        vector<vector<int>> dp(x+1,vector<int>(y+1,0));
        //shifting one index to right as our base case is for -1 index
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
	int minOperations(string str1, string str2) 
	{ 
	    int n=lcs(str1,str2);
	    return str1.size()+str2.size()-2*n;
	    
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends