class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& a) {
        int n=a.size();
        if(n==1){return 0;}
        int dif=a[1]-a[0],cur=2;
        int ans=0;
        for(int i=2;i<=n;i++){
            if(i==n){
                if(cur>=3){
                   ans+=(cur*(cur-2));
                   ans-=(((cur*(cur-1))/2)-1);
                }
                break;
            }
            if(a[i]-a[i-1]==dif){cur++;}
            else{
                if(cur>=3){
                   ans+=(cur*(cur-2));
                   ans-=(((cur*(cur-1))/2)-1);
                }
                cur=2;dif=a[i]-a[i-1];
            }
        }
        return ans;
    }
};