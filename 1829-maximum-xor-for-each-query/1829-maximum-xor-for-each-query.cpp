class Solution {
public:
    vector<int> getMaximumXor(vector<int>& a, int maximumBit) {
        int n=a.size();
        vector<int> pre(n);
        pre[0]=a[0];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]^a[i];
        }
        vector<int> ans;
        while(n-1>=0){
            int cur=pre[n-1];
            int i=0,k=0;
            while(i<maximumBit){
                if((cur&(1<<i))==0){k+=(1<<i);}
                i++;
            }
            ans.push_back(k);
            n--;
        }
        return ans;
    }
};