class Solution {
public:
    int searchInsert(vector<int>& a, int target) {
        int n=a.size();
        int l=0,r=n-1;
        bool b=true;
        while(l<=r){
            int m=l+(r-l)/2;
            if(a[m]==target){return m;}
            else if(a[m]>target){r=m-1;b=false;}
            else{l=m+1;b=true;}
        }
       return l; 
    }
};