class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        int l=0,r=n-1,ans=-1;
        while(l<=r){
            int m=l+(r-l)/2;
            int left=n-m;
            if(left>=citations[m]){
                ans=max(ans,citations[m]);l=m+1;
            }else{
                ans=max(ans,left);r=m-1;
            }
        }
        return ans;
    }
};