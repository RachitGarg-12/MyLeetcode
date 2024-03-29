class Solution {
public:
    bool pos(int m,vector<int>a,int h){
        int n=a.size();int t=0;
        for(int i=0;i<n;i++){
            t += a[i]%m==0 ? a[i]/m : (a[i]/m)+1;
            if(t>h)return false;
        }
       return true;    
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1,r=0;int ans=0;
        for(auto i:piles){r=max(r,i);}
        while(l<=r){
            int m=l+(r-l)/2;
            if(pos(m,piles,h)){ans=m;r=m-1;}
            else{l=m+1;}
        }
        return ans;
    }
};