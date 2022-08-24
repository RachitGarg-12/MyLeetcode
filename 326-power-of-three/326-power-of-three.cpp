class Solution {
public:
    bool isPowerOfThree(int n) {
        long long i=1;
        while(i<=n){
            if(i==n){return true;}
            i*=3;
        }
        return false;
    }
};