class Solution {
public:
    int maxSubarraySumCircular(vector<int>& a) {
        int mx=-1e9,sum=0;
        int n=a.size();
        for(auto i:a){sum+=i;mx=max(mx,i);}
        if(mx<=0){return mx;}
        int mxdp[n],mndp[n];
        mxdp[0]=a[0];mndp[0]=a[0];
        int ans=0;
        for(int i=1;i<n;i++){
            mxdp[i]=max(mxdp[i-1]+a[i],a[i]);
            mndp[i]=min(mndp[i-1]+a[i],a[i]);
            ans=max(ans,max(mxdp[i],sum-mndp[i]));
        }
        return ans;
    }
};