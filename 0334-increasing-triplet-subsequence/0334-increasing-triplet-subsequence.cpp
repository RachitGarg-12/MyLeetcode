class Solution {
public:
    bool increasingTriplet(vector<int>& a) {
        int n=a.size();long long f=a[0],s=1e10,t=1e10;bool b=false;
        for(int i=1;i<n;i++){
            if(a[i]>s){t=a[i];b=true;break;}
            if(a[i]<=f){f=a[i];}
            else{s=a[i];}
        }
       return b;
    }
};