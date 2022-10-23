//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:

    int steppingNumbers(int n, int m){
                int ans=0;
         queue<int> q;
        for(int i=0;i<=9;i++)
           q.push(i);
        while(!q.empty()){
            int stepnum=q.front();
            q.pop();
            if(stepnum>=n && stepnum<=m)
            ans++;
            
            if(stepnum==0 || stepnum>m) continue;
            int lastdigit=stepnum%10;
            int stepnum1=stepnum*10 + lastdigit-1;
            int stepnum2=stepnum*10+lastdigit+1;
            if(lastdigit==0)   q.push(stepnum2);
            else if(lastdigit==9)  q.push(stepnum1);
            else{
                q.push(stepnum1);
                q.push(stepnum2);
            }

        }    
            
            
            
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    Solution obj;
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;
        cout << obj.steppingNumbers(n,m) << endl;
    }
	return 0;
}


// } Driver Code Ends