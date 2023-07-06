class Solution {
public:
    int minSubArrayLen(int target, vector<int>& a) {
        int n=a.size();
        vector<int> pre(n);
        pre[0]=a[0];
        for(int i=1;i<n;i++){
            pre[i]=a[i]+pre[i-1];
        }
        if(pre[n-1]<target){return 0;}
        int i=-1,cur=0,ans=n;
        for(int j=0;j<n;j++){
            cur=pre[j]-((i>=0)?pre[i]:0);
            // cout<<i<<" "<<j<<" "<<cur<<endl;
            while(i<j && cur>=target){
                ans=min(ans,j-i);
                i++;
                cur=pre[j]-((i>=0)?pre[i]:0);
            }
        }
        return ans;
    }
};
