class Solution {
public:
    int n;
    bool pred(int m,vector<int> &a,int days){
        int cur_day=1,cur_weight=0;
        for(int i=0;i<n;i++){
            if(cur_weight+a[i]<=m){cur_weight+=a[i];}
            else{
                cur_day++;cur_weight=a[i];
                if(cur_day>days){return false;}
            }
        }
        return true;
    }
    int shipWithinDays(vector<int>& a, int days) {
        int sum=0;n=a.size();
        int mx=0;
        for(auto it:a){sum+=it;mx=max(mx,it);}
        int l=mx,r=sum;int ans=sum;
        while(l<=r){
            int m=l+(r-l)/2;
            if(pred(m,a,days)){ans=m;r=m-1;}
            else{l=m+1;}
        }
        return ans;
    }
};