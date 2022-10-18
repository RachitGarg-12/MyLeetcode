class Solution {
public:
    bool pred(int m,vector<int>& a,int mx){
        long tot=0;int n=a.size();long comb=n+mx;
        for(int i=0;i<n;i++){
            if(a[i]>m){
                tot+=a[i]/m;if(a[i]%m>0){tot++;}
                if(tot>comb){return false;}
            }else{tot++;
                  if(tot>comb){return false;}}
        }
      
        return true;
    }
    int minimumSize(vector<int>& a, int mx) {
        int l=1,r=1,ans;
        for(auto it:a){r=max(r,it);}
        ans=r;
        while(l<=r){
            long m=l+(r-l)/2;
            if(pred(m,a,mx)){ans=m;r=m-1;}
            else{l=m+1;}
        }
        return ans;
    }
};