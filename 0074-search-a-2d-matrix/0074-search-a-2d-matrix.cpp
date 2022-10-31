class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int t) {
        int n=a.size(),m=a[0].size();
        int l=0,r=n-1;int ind=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(a[mid][m-1]>=t){ind=mid;r=mid-1;}
            else{l=mid+1;}
        }
        cout<<ind<<endl;
        if(ind==-1)return false;
        l=0,r=m-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(a[ind][mid]==t){return true;}
            else if(a[ind][mid]>t){r=mid-1;}
            else{l=mid+1;}
        }
        return false;
    }
};