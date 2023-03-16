#define ll long long
class Solution {
public:
    const int mod=1e9+7;
    int maxSum(vector<int>& a, vector<int>& b) {
        int n=a.size(),m=b.size();
        unordered_map<int,int> fre,ind;
        vector<pair<int,int>> bridge;
        vector<ll> pre1(n),pre2(m);
        pre1[0]=a[0];pre2[0]=b[0];
        for(int i=0;i<n;i++){
            fre[a[i]]++;
            ind[a[i]]=i;
            if(i!=0){pre1[i]=pre1[i-1]+a[i];}
        }
        for(int i=0;i<m;i++){
            fre[b[i]]++;
            if(fre[b[i]]>1){bridge.push_back({i,b[i]});}
            if(i!=0){pre2[i]=pre2[i-1]+b[i];}
        }
        if(bridge.size()==0){return max(pre1[n-1],pre2[m-1]);}
        int lastb=bridge[0].first;
        int lasta=ind[bridge[0].second];
        ll ans=max(pre1[lasta],pre2[lastb]);
        bool bl=true;
        for(auto i:bridge){
            if(bl){bl=false;continue;}
            int ele=i.second;
            int indb=i.first-1;
            int inda=ind[ele]-1;
            ll suma=(pre1[inda]-pre1[lasta]);
            ll sumb=(pre2[indb]-pre2[lastb]);
            ans+=max(suma,sumb);
            lasta=inda;lastb=indb;
        }
        ans+=max(pre1[n-1]-pre1[lasta],pre2[m-1]-pre2[lastb]);
        return ans%mod;
    }
};