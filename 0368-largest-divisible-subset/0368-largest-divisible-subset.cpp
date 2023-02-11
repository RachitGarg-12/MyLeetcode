class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& a) {
        int n=a.size();
        sort(a.begin(),a.end());
        vector<int> dp(n,1),hash(n);
        int mx=1,lastindex=0;
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                if(a[i]%a[j]==0 && dp[j]+1>dp[i]){
                    dp[i]=1+dp[j];
                    hash[i]=j;
                }
            }
            if(dp[i]>mx){
                mx=dp[i];
                lastindex=i;
            }
        }
        vector<int> ans;
        ans.push_back(a[lastindex]);
        while(hash[lastindex]!=lastindex){
            lastindex=hash[lastindex];
            ans.push_back(a[lastindex]);
        }
        if(ans.size()==0){ans.push_back(a[0]);}
        return ans;
    }
};