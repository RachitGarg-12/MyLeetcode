class Solution {
public:
    const long long mod=1e9+7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        long long n=arr.size();long long ans=0;
        sort(arr.begin(),arr.end());
        unordered_map<long long,long long> dp ;
        dp[arr[0]]=1;
       
        for(int i=1;i<n;i++){
            long long way=1;
          for(auto j:dp){
              if(arr[i]%j.first==0 && dp.find(arr[i]/j.first)!=dp.end()){
                  way += ((dp[j.first]%mod)*(dp[arr[i]/j.first]%mod))%mod;way %=mod;
              }
          }
            dp[arr[i]]=way;
        }
        
        for(auto i:dp){ans += i.second;ans%=mod; }
        return ans;
    }
};