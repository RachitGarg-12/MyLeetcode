class Solution {
public:
    int numRescueBoats(vector<int>& a, int limit) {
        int n=a.size();
        sort(a.begin(),a.end());
        int st=0,en=n-1;
        int ans=0;
        while(st<en){
            if(a[en]+a[st]<=limit){st++;en--;}
            else{en--;}
            ans++;
        }
        if(st==en){ans++;}
        return ans;
    }
};