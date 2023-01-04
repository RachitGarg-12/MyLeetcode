class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ans=0;
        for(long long i=1;i<=left;i<<=1){
            long long n=left;
            bool b=true;
            while(n<=right){
                if((n&i)==0){b=false;break;}
                n++;
            }
            if(b){ans+=i;}
        }
        return ans;
    }
};