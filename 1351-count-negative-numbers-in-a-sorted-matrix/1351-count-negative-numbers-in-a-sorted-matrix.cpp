class Solution {
public:
    int countNegatives(vector<vector<int>>& a) {
        int n=a.size(),m=a[0].size(),tot=0;
        for(int i=0;i<n;i++){
           int l=0,r=m-1,ans=m;
            while(l<=r){
                int mid=l+(r-l)/2;
                if(a[i][mid]<0){ans=mid;r=mid-1;}
                else{l=mid+1;}
            }
            tot+=m-ans;
        }
        return tot;
    }
};