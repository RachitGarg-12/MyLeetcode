class Solution {
public:
    int maxProduct(vector<int>& a) {
        int n=a.size();
        int prev=a[0];int ans=a[0];
        for(int i=1;i<n;i++){
            if(prev==0){prev=1;}
            int curr= prev*a[i];
            ans=max(ans,curr);
            prev=curr;
        }
        int pre=a[n-1];ans=max(ans,pre);
        for(int i=n-2;i>=0;i--){
          if(pre==0){pre=1;}
            int curr= pre*a[i];
            ans=max(ans,curr);
            pre=curr;
        }
        return ans;
    }
};