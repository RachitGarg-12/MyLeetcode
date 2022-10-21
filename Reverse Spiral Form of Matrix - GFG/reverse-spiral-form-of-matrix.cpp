//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> reverseSpiral(int r, int c, vector<vector<int>>&a)  {
        bool rf=true,cd=false,rb=false,cu=false;
        vector<vector<int>> vis(r,vector<int>(c,0));
        vector<int> ans;
        for(int i=0;i<c;i++){vis[0][i]=1;ans.push_back(a[0][i]);}
        for(int i=1;i<r;i++){vis[i][c-1]=1;ans.push_back(a[i][c-1]);}
        if(r-1!=0){for(int i=c-2;i>=0;i--){vis[r-1][i]=1;ans.push_back(a[r-1][i]);}}
        if(c-1!=0){for(int i=r-2;i>0;i--){vis[i][0]=1;ans.push_back(a[i][0]);}}
        int i=1,j=1;
        if(i>=r || j>=c){
            reverse(ans.begin(),ans.end());
            return ans;}
        
        while(vis[i][j]==0){
            if(rf==true){
                if(vis[i][j]==1){break;}
                for(int k=j;k<c;k++){
                    if(vis[i][k]==1){i++;j=k-1;cd=true;rf=false;break;}
                    ans.push_back(a[i][k]);vis[i][k]=1;
                }
            }
            if(cd==true){
                if(vis[i][j]==1){break;}
                for(int k=i;k<r;k++){
                    if(vis[k][j]==1){j--;i=k-1;rb=true;cd=false;break;}
                    ans.push_back(a[k][j]);vis[k][j]=1;
                }
            }
            if(rb==true){
                if(vis[i][j]==1){break;}
                for(int k=j;k>=0;k--){
                    if(vis[i][k]==1){i--;j=k+1;cu=true;rb=false;break;}
                    ans.push_back(a[i][k]);vis[i][k]=1;
                }
            }
            if(cu==true){
                if(vis[i][j]==1){break;}
                for(int k=i;k>=0;k--){
                    if(vis[k][j]==1){j++;i=k+1;rf=true;cu=false;break;}
                    ans.push_back(a[k][j]);vis[k][j]=1;
                }
            }
            
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin>>R>>C;
        vector<vector<int>> a(R, vector<int>(C, 0));
        for(int i = 0;i < R*C;i++)
            cin>>a[i/C][i%C];
        Solution ob;
        vector<int>ans=ob.reverseSpiral(R,C,a);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
            cout<<endl;
    }
    return 0;
}

// } Driver Code Ends