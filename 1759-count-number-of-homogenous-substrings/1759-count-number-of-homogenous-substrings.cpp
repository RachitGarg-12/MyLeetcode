class Solution {
public:
    const int mod=1e9+7;
    int countHomogenous(string s) {
        int n=s.size();
        long long int cur=1,ans=0;
        for(int i=1;i<n;i++){
            if(s[i]!=s[i-1]){
                ans += (((cur%mod)*((cur+1)%mod))/2)%mod;
                cur=1;
            }
            else{cur++;}
        }
        ans += (((cur%mod)*((cur+1)%mod))/2)%mod;
        return ans;
    }
};