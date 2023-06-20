class Solution {
public:
    int arrangeCoins(int n) {
        long long l=1,r=n,ans=-1;
        while(l<=r){
            long long m=l+(r-l)/2;
            if((m*(m+1))/2<=n){ans=m;l=m+1;}
            else{r=m-1;}
        }
        return ans;        
    }
};