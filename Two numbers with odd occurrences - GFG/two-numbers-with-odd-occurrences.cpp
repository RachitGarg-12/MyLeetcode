//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        long long int ans = 0;
        long long int last=0;
        for(int i = 0 ;i<N;++i){
            ans^=Arr[i];
        }
   
        while(true){
            if((ans & (1LL<<last)) > 0){break;}
            last++;
        }
        long long int a=0,b=0;
        for(int i = 0;i<N ;++i){
            if(Arr[i]& (1LL<<last)) a^=Arr[i];
            else b^=Arr[i];
        }
        vector<long long int> v;
        v.push_back(max(a,b));
        v.push_back(min(a,b));
        return v;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends