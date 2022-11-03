class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& a) {
        sort(a.begin(),a.end());int n=a.size();
        int ans=0;int rb=a[0][1];
        for(int i=1;i<n;i++){
            if(a[i][0]<rb){ans++;rb=min(rb,a[i][1]);}
            else{rb=a[i][1];}
        }
        return ans;
    }
};