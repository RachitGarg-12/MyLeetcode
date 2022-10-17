//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	public:
	vector<int> downwardDigonal(int n, vector<vector<int>> a)
	{   int i=0,j=0;vector<int> ans;bool up=true,side=false;
		while(i<=n-1 && j<=n-1){
		    if(up==true && side==false && j==n-1){
		        int tempi=i,tempj=j;
		        while(tempj>=0){
		            ans.push_back(a[tempi][tempj]);tempi++;tempj--;
		        }
		        up=false;side=true;i++;
		    }
		    else if(up){
		        int tempi=i,tempj=j;
		        while(tempj>=0){
		            ans.push_back(a[tempi][tempj]);tempi++;tempj--;
		        }
		        j++;
		    }
		    else if(side){
		        int tempi=i,tempj=j;
		        while(tempi<=n-1){
		            ans.push_back(a[tempi][tempj]);tempi++;tempj--;
		        }
		        i++;
		    }
		}
		return ans;
	}

};

//{ Driver Code Starts.



int main()
{

    
    int t;
    cin >> t;
    while(t--) 
    {
        int n;
        cin >> n;

        vector<vector<int>> A(n, vector<int>(n));

        for(int i = 0; i < n; i++)
        	for(int j = 0; j < n; j++)
        		cin >> A[i][j];

        Solution obj;
        vector<int> ans = obj.downwardDigonal(n, A);

        for(auto i:ans)
        	cout << i << " ";

	    cout << "\n";
    }

    return 0;
}

// } Driver Code Ends