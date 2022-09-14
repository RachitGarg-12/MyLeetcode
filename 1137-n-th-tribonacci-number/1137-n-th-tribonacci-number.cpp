class Solution {
public:
    int tribonacci(int n) {
        int f=0,s=1,th=1;
        if(n==0){return f;}
        if(n==1){return s;}
        for(int i=3;i<=n;i++){
            int cur=f+s+th;
            f=s;s=th;th=cur;
        }
        return th;
    }
};