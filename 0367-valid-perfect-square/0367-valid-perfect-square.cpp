class Solution {
public:
    bool isPerfectSquare(int num) {
        long long l=1,r=num,ans=-1;
        while(l<=r){
            long long m=l+(r-l)/2;
            if(m*m==num){return true;}
            else if(m*m>num){r=m-1;}
            else{l=m+1;}
        }
        return false;
    }
};