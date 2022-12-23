class Solution {
public:
    int maxProfit(vector<int>& a) {
        int mn=a[0];
        int n=a.size();int ans=0;
        for(int i=1;i<n;i++){
            if(a[i]>mn){ans=max(ans,a[i]-mn);}
            else{mn=a[i];}
        }
        return ans;
    }
};