//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
 
    int maxMeetings(int start[], int end[], int n)
    {
        vector<vector<int>> s;
        for(int i=0;i<n;i++){
            s.push_back({end[i],start[i]});
        }
        sort(s.begin(),s.end());
        int ans=1;
        int last=s[0][0];
        for(int i=1;i<n;i++){
            if(s[i][1]>last){ans++;last=s[i][0];}
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends