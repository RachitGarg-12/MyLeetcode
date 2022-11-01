class Solution {
public:
    int search(vector<int>& a, int target) {
        int n=a.size();
        int l=0,r=n-1,ans=-1;
        if(a[n-1]==target){return n-1;}
        while(l<=r){
            // cout<<l<<" "<<r<<endl;
            int m=l+(r-l)/2;
           if(a[m]==target){ans=m;break;}
           if(a[m]>a[n-1]){
                if(target>a[n-1]){
                    if(a[m]>target){r=m-1;}
                    else{l=m+1;}}
                else{
                    l=m+1;
                }
            }
            else{
                 if(target<a[n-1]){
                     if(a[m]>target){r=m-1;}
                    else{l=m+1;}}
                else{r=m-1;}
            }
        }
        return ans;
    }
};