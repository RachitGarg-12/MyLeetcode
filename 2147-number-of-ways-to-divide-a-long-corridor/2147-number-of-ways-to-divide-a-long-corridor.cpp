class Solution {
public:
    long long mod=1e9+7;
    int numberOfWays(string corridor) {
        int seats=0;
        for(auto &i:corridor){
            if(i=='S'){seats++;}
        }
        if(seats<2 || seats%2){return 0;}
        int divider=(seats/2)-1;
        long long ans=1,cur=0,p=0;
        bool b=false;
        for(auto i:corridor){
            if(b && i=='P'){p++;}
            if(i=='S'){
                if(b){
                    ans=((ans%mod)*((p+1)%mod))%mod;
                    b=false;p=0;
                }
               cur++;
                if(cur==2){b=true;cur=0;}
            }
        }
        return ans;
    }
};