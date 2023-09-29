class Solution {
public:
    bool isMonotonic(vector<int>& a) {
        int n=a.size();
        bool inc=false,dec=false;
        if(a[0]>a[n-1]){dec=true;}
        else{inc=true;}
        for(int i=1;i<n;i++){
            if(inc){
                if(a[i-1]>a[i]){return false;}
            }else{
                if(a[i-1]<a[i]){return false;}
            }
        }
        return true;
    }
};