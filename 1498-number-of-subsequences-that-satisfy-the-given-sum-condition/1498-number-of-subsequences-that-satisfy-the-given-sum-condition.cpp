class Solution {
public:
    long long expo(long long a, long long b, long long mod) {long long res = 1; while (b > 0) {if (b & 1)res = ((res%mod) * (a%mod)) % mod; a = ((a%mod) * (a%mod)) % mod ; b = b >> 1;} return res%mod;}
    int mod=1e9+7;
    int numSubseq(vector<int>& a, int tar) {
        int n=a.size();
        sort(a.begin(),a.end());
        int i=0,j=n-1;
        long long ans=0;
        while(i<=j){
            if(a[i]+a[j]<=tar){
                if(j==i){ans++;break;}
                if(j-i-1>=0){
                    long long way=expo(2,j-i,mod);
                    ans=(ans%mod+way%mod)%mod;
                }
                i++;
            }
            else{j--;}
        }
        return ans;
    }
};