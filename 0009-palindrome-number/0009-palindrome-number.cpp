class Solution {
public:
    bool isPalindrome(int n) {
        if(n<0)return false;
        long long r,sum = 0,k=n;
        while(n>0){
            r = n%10;
            sum*=10;sum+=r;
            n/=10;}
        if(k==sum){return true;}
        return false;
    }
};