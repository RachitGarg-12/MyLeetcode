class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int mx=max(abs(sx-fx),abs(sy-fy));
        if(mx==0 && t==1){return false;}
        return mx<=t;
    }
};