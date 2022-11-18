class Solution {
public:
    bool isUgly(int n) {
        if(n<=0)return false;
        for (long long i=2;(long long)i*i<=n;i++){
            while(n%i==0){
                if(i>5)return false;
                n/=i;}
        }
        if(n>2){
            if(n>5)return false;
        }
        return true;
    }
};