class Solution {
public:
    int n;
    int getnext(int i,vector<vector<int>> &a){   //find next ind whose st > en of cur
        int l=i+1,r=n-1,ans=n;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(a[i][1]<=a[mid][0]){
                ans=mid;r=mid-1;
            }else{l=mid+1;}
        }
        return ans;
    }
    int f(int i,vector<vector<int>> &a,vector<int> &dp){
        if(i>=n){return 0;}
        if(dp[i]!=-1){return dp[i];}
        int nt=f(i+1,a,dp);  //not take cur
        int in=getnext(i,a);
        int take=a[i][2]+f(in,a,dp); //take cur , and go to next element whose start greater than en of cur
        return dp[i]=max(nt,take);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n=startTime.size();
        vector<vector<int>> a;
        for(int i=0;i<n;i++){
            a.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(a.begin(),a.end());
        vector<int> dp(n,-1);
        return f(0,a,dp);
    }
};