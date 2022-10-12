//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
   string maxSum(string w,char x[], int b[],int n){
          // code here  
          if(w.length()==1)
          return w;
          int maxe = 0;
          string ans = "";
          string temp="";
          int curr = 0;
          map<char,int> mp;
          for(int i = 0;i<n;i++)
          {
              mp[x[i]] = b[i];
          }
        //   string temp ="";
          for(int i = 0;i<w.length();i++)
          {
             if(mp.find(w[i])==mp.end())
                 curr+=(int)w[i];
             else
                 curr+=mp[w[i]];
             temp+=w[i];
             if(curr>maxe)
             {
                 maxe = curr;
                 ans = temp;
             }
             if(curr<0)
             {
                 curr=0;
                 temp="";
             }
                
          }
           if(curr>maxe)
           ans = temp;
          return ans;
      }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string w;
        cin>>w;
        int n;
        cin>>n;
        char x[n];
        int b[n];
        for(int i = 0;i<n;i++)
            cin>>x[i];
        for(int i = 0;i<n;i++)
            cin>>b[i];
        Solution ob;
        cout << ob.maxSum(w,x,b,n) << endl;
    }
    return 0; 
}
// } Driver Code Ends