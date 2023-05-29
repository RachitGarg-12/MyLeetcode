#define ll long long
class Solution {
public:
   ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a)     %mod; b = b >> 1;} return res;}
    int mod=1e9+7;
    int numSubseq(vector<int>& a, int tar) {
        int n=a.size();
        sort(a.begin(),a.end());
        int i=0,j=n-1;
        ll ans=0;
        while(i<=j){
            if(a[i]+a[j]<=tar){
                if(j==i){ans++;break;}
                if(j-i-1>=0){
                    ll way=expo(2,j-i,mod);
                    ans=(ans%mod+way%mod)%mod;
                }
                i++;
            }
            else{j--;}
        }
        return ans;
    }
};