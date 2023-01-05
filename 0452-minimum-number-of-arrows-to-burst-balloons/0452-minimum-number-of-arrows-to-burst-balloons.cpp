class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& a) {
        int n=a.size();
        sort(a.begin(),a.end());
        int ans=1;
        int en=a[0][1];
        for(int i=1;i<n;i++){
            if(a[i][0]<=en){en=min(en,a[i][1]);}
            else{ans++;en=a[i][1];}
        }
        return ans;
    }
};